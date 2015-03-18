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
#include "GeographicLib/TransverseMercator.hpp"

#include "main_conversion.h"

#define PI 3.14159265
#define EPSILON 23.439281

using namespace std;
using namespace GeographicLib;


/// MAIN


/// Définitions des fonctions de conversion

void changementRepere (double &lat, double &longitude, double alpha, double delta) //Passage des coordonnées célestes aux coordonnées géographiques
{
    double SinLat, CosLongXCosLat, SinLongXCosLat;
	
	alpha = enRadians(alpha);
	delta = enRadians(delta);
	
	//Formules de changement de repère 
	SinLat = cos(enRadians(EPSILON))*sin(delta)-sin(EPSILON)*sin(alpha)*cos(delta);
    CosLongXCosLat = cos(alpha)*cos(delta);
	SinLongXCosLat = sin(EPSILON)*sin(delta)+cos(EPSILON)*sin(alpha)*cos(delta);
	
	//Calcul de lat et long
	lat = asin(SinLat); //Parce que lat est compris entre -PI/2 et PI/2
	
	if(CosLongXCosLat > 0) //Equivalent à cosLong > 0 
	{
		longitude = asin(SinLongXCosLat/cos(lat));
	}
	
	if(CosLongXCosLat <= 0 && SinLongXCosLat > 0)
	{
		longitude = acos(CosLongXCosLat/cos(lat));
	}
	
	if(CosLongXCosLat <= 0 && SinLongXCosLat <= 0)
	{
		longitude = PI - asin(-SinLongXCosLat/cos(lat));
	}
}

double enRadians (double angle)
{
	return (angle*PI)/180;
}

positionPlan forward(positionTerrestre in, double meridian){
    positionPlan out;

    try {
        TransverseMercator proj(Constants::WGS84_a(), Constants::WGS84_f(), Constants::UTM_k0());
        // Alternatively: const TransverseMercator& proj = TransverseMercator::UTM;
        //double lon0 = -75; // Central meridian for UTM zone 18
        {
            // Sample forward calculation
            cout << "Forward : ";
            double x, y;
            proj.Forward(meridian, in.latitude, in.longitude, x, y);
            cout << x << " " << y << "\n";

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

int main(){

    ifstream catalogue("../src/cat.txt");
    if (!catalogue)
    {
        std:cerr<<"Cannot open the input file."<<std::endl;
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
            // On récupère la valeur
            ciel.declination = atoi(mot.c_str());

            // On passe au repère terrestre
            changementRepere(sol.latitude, sol.longitude, ciel.rightascension, ciel.declination);
            cout << "Terre : " << sol.latitude << " " << sol.longitude << endl;

            // On calcule le meridien de projection
            int Zone = long2UTM(sol.longitude);
            double _meridian = meridian(Zone);
            cout << "Zone : " << Zone << " Longitude : " << _meridian << endl;

            // On projete sur le sol
            plan = forward(sol, _meridian);
            cout << endl;


            // On écrit dans le fichier texte
            stringstream ssX, ssY;
            ssX << plan.x;
            string sX = ssX.str();
            ssY << plan.y;
            string sY = ssY.str();
            sortie << sX << " " << sY << '\n';

        }
    }
    //}
    sortie.close();

    return 0;
}








