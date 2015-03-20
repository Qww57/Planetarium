/**
 * \file main_conversion.cpp
 * \brief conversion des coordonnées
 * \author Quentin.T
 * \version 0.1
 * \date 11 mars 2015
 *
 *
 *
 */


#include <iostream>
#include <exception>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include "GeographicLib/TransverseMercator.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>

#include "main_conversion.h"

#define PI 3.14159265
#define EPSILON 23.439281

using namespace std;
using namespace cv;
using namespace GeographicLib;


int nbErreur;

/// MAIN


/// Définitions des fonctions de conversion

void changementRepere (double &lat, double &longitude, double alpha, double delta, int &nbErreur) //Passage des coordonnées célestes aux coordonnées géographiques
{
    double SinLat, CosLongXCosLat, SinLongXCosLat;
	
    alpha = enRadians(alpha);
    //cout << "ALPHA : " << alpha << endl;
    delta = enRadians(delta);
    //cout << "DELTA : " << delta << endl;
	
	//Formules de changement de repère 
    SinLat = cos(enRadians(EPSILON))*sin(delta)-sin(enRadians(EPSILON))*sin(alpha)*cos(delta);
    //cout << "SINLAT : " << SinLat << endl; //PB
    CosLongXCosLat = cos(alpha)*cos(delta);
    //cout << "COSLONGXCOSLAT : " << CosLongXCosLat << endl;
    SinLongXCosLat = sin(enRadians(EPSILON))*sin(delta)+cos(enRadians(EPSILON))*sin(alpha)*cos(delta);
    //cout << "SINLONGXCOSLAT : " << SinLongXCosLat << endl;
	
	//Calcul de lat et long
	lat = asin(SinLat); //Parce que lat est compris entre -PI/2 et PI/2
    //cout << "LAT : " << lat << endl;

    lat = enDegres(lat);
    if ((lat>90) | (lat < (-90)))
    {
        nbErreur ++;
        cout << "ERREUR LATITUDE : " << lat << endl;
    }

	if(CosLongXCosLat > 0) //Equivalent à cosLong > 0 
	{
		longitude = asin(SinLongXCosLat/cos(lat));
        //cout << "LONGITUDE : " << longitude << endl;
	}
	
	if(CosLongXCosLat <= 0 && SinLongXCosLat > 0)
	{
		longitude = acos(CosLongXCosLat/cos(lat));
        //cout << "LONGITUDE : " << longitude << endl;
	}
	
	if(CosLongXCosLat <= 0 && SinLongXCosLat <= 0)
	{
		longitude = PI - asin(-SinLongXCosLat/cos(lat));
        //cout << "LONGITUDE : " << longitude << endl;
	}

    longitude = enDegres(longitude);
    if ((longitude > 180) | (longitude < (-180)))
    {
        nbErreur ++;
        cout << "ERREUR LONGITUDE : " << longitude << endl;
    }
}

double enRadians (double angle)
{
	return (angle*PI)/180;
}

double enDegres (double angle){
    return (angle*180)/PI;
}

positionPlan forward(positionTerrestre in, double meridian){
    positionPlan out;

    try {
        TransverseMercator proj(Constants::WGS84_a(), Constants::WGS84_f(), Constants::UTM_k0());
        // Alternatively: const TransverseMercator& proj = TransverseMercator::UTM;
        //double lon0 = -75; // Central meridian for UTM zone 18
        {
            // Sample forward calculation
            //cout << "Forward : ";
            double x, y;
            proj.Forward(meridian, in.latitude, in.longitude, x, y);
            //cout << x << " " << y << "\n";

            out.x = x;
            out.y = y;
        }
    }
    catch (const exception& e)
    {
        cerr << "Caught exception: " << e.what() << "\n";
    }

    return out;
}

positionTerrestre reverse(positionPlan in){
    positionTerrestre out;
    try {
        TransverseMercator proj(Constants::WGS84_a(), Constants::WGS84_f(), Constants::UTM_k0());
        // Alternatively: const TransverseMercator& proj = TransverseMercator::UTM;
        double lon0 = -75; // Central meridian for UTM zone 30 T
        {
            // Sample reverse calculation
            //cout << "Reverse : ";
            double x = 25e3, y = 4461e3;
            double lat, lon;
            proj.Reverse(lon0, in.x, in.y, lat, lon);
            //cout << lat << " " << lon << "\n";
            out.latitude = lat;
            out.longitude = lon;
        }
    }
    catch (const exception& e)
    {
        cerr << "Caught exception: " << e.what() << "\n";
    }
}


/// Decoupage de la map en différents méridiens de développement

int long2UTM (int Long){        
    int temp = floor(((Long%360) + 180)/6);
    int ZoneUTM = temp%60+ 1;
    return ZoneUTM;
}

double meridian(int zone){
    /// zone 30 angleterre : méridian : 0
    /// zone 31 : meridian : 6
    /// zone 60 : meridian : 180
    /// zone 29 : meridian : -6
    /// zone 0 : meridian : -180

    double longitude;
    longitude = ((zone-30)*6) %360;
    return longitude;
}


/// MAIN

// RA = longitude .. DEC = latitude

// Unités de Valentin ?
// Unités de la conversion changement de repère ?
// Unités de Forward ?

// Affichage du plan: si affichage = 1 : ON
#define AFFICHAGE 1

int main(){

    ifstream catalogue("../src/cat.txt");
    if (!catalogue)
    {
        std:cerr<<"Cannot open the input file."<<std::endl;
    return -1;
    }

    ofstream debug("../Rendu/CatalogueDebug.txt");
    if(!debug)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
    return -1;
    }

    ofstream sortie("../Rendu/CatalogueProjete.txt");
    if(!sortie)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
	return -1;
    }

    positionTerrestre sol;
    positionCelestre ciel;
    positionPlan plan;


    int height = 720;
    int width = 1280;
    Mat image = Mat::zeros( height, width, CV_8UC3 );
    vector<Point> liste;

    nbErreur = 0;
    int lines = 0;
    int compteur = 0;
    string mot;

    //for (int i=0 ; i <3; i++){
    while (!catalogue.eof()){
        catalogue >> mot;
        // cout << mot << endl;

        compteur = compteur + 1;

         if (compteur %3 == 1)
         {
            sortie << mot << " ";
         }
         if (compteur %3 == 2)
         {
            ciel.rightascension = atoi(mot.c_str());
         }
         if (compteur %3 == 0)
         {
            lines ++;

             // On récupère la valeur
            ciel.declination = atoi(mot.c_str());

            // On passe au repère terrestre
            changementRepere(sol.latitude, sol.longitude, ciel.rightascension, ciel.declination, nbErreur);
            //cout << "Terre : " << sol.latitude << " " << sol.longitude << endl;

            // On calcule le meridien de projection
            int Zone = long2UTM(sol.longitude);
            double _meridian = meridian(Zone);
            //cout << "Zone : " << Zone << " Longitude : " << _meridian << endl;

            // On projete sur le sol
            plan = forward(sol, _meridian);
            //cout << endl;


            // On écrit dans le fichier texte
            stringstream debugX, debugY;
            debugX << sol.latitude;
            string dX = debugX.str();
            debugY << sol.longitude;
            string dY = debugY.str();
            debug << dX << " " << dY << '\n';


            // On écrit dans le fichier texte
            stringstream ssX, ssY;
            ssX << plan.x;
            string sX = ssX.str();
            ssY << plan.y;
            string sY = ssY.str();
            sortie << sX << " " << sY << '\n';

            if (AFFICHAGE == 1)
            {
                if ((!isnan(plan.x))&&(!isnan(plan.y)))
                {
                    int X = (plan.x)/1000; cout << " X " << X;
                    int Y = (plan.y)/10000; cout << " Y " << Y << endl;
                    Point tmp(X,Y);
                    liste.push_back(tmp);
                }
            }
        }
    }
    //}
    cout << "DONE " << endl;
    cout << "Liste " << liste.size() << endl;
    cout << "Nombre d'erreurs : " << nbErreur << endl;
    float ratio = 100.0 * (float) nbErreur / ((float) lines);
    cout << "Ratio d'erreur : " << ratio << endl;



    if (AFFICHAGE == 1){
        //affichage(&image, liste);
        cout << "je vais lancer l'affichage " << endl;

        for (int i = 0; i < 10 ; i++){
            circle(image, liste[i], 1, Scalar(0,0,255), 1, 8, 0 );
            cout << i << endl;
        }
        cout << "Fin boucle " << endl;

        int key =  waitKey(0);
        if (key != -1)
            cout << waitKey<< endl;

        cout << "After WK" << endl;

        namedWindow("Debug_Plan");
        imshow("Debug_Plan", image);

        cout << "After imshow" << endl;
    }

    sortie.close();

    return 0;
}
/*
void affichage(Mat *image, vector<Point> liste){

    cout << "je vais lancer l'affichage " << endl;

    for (int i = 0; i < 10 ; i++){
        circle(image, liste[i], 1, Scalar(0,0,255), 1, 8, 0 );
        cout << i << endl;
    }
    cout << "Fin boucle " << endl;

    int waitKey(30);

    cout << "After WK" << endl;

    namedWindow("Debug_Plan");
    imshow("Debug_Plan", image);

    cout << "After imshow" << endl;
}
*/





