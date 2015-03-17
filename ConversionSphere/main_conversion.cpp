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
	
	//Formules de changement de repère 
	SinLat = cos(enRadians(EPSILON))*sin(delta)-sin(EPSILON)*sin(alpha)*cos(delta);
    CosLongXCosLat = cos(alpha)*cos(delta);
	SinLongXCosLat = sin(EPSILON)*sin(delta)+cos(EPSILON)*sin(alpha)*cos(delta);
	
	//Calcul de lat et long
	lat = asin(SinLat); //Parce que lat est compris entre 0 et PI/2
	
	if(CosLongXCosLat > 0) //Equivalent à cosLong > 0 
	{
		longitude = asin(SinLongXCosLat/cos(lat));
	}
	
	else 
	{
        longitude = acos(CosLongXCosLat/cos(lat));
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
            cout << "Reverse : ";
            double x = 25e3, y = 4461e3;
            double lat, lon;
            proj.Reverse(lon0, in.x, in.y, lat, lon);
            cout << lat << " " << lon << "\n";
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
    int ZoneUTM = (floor((Long + 180)/6) % 60) + 1;
    return ZoneUTM;
}

double meridian(int zone){
    /// zone 30 angleterre : méridian : 0
    /// zone 31 : meridian : 6
    /// zone 60 : meridian : 180
    /// zone 29 : meridian : -6
    /// zone 0 : meridian : -180

    double longitude;
    longitude = (zone-30)*6;

    return longitude;
}


/// MAIN

void projection(ifstream &catalogue, ofstream &sortie){

    positionTerrestre sol;
    positionCelestre ciel;
    positionPlan plan;

    int compteur = 0;
    string mot;

    while (catalogue >> mot)
    {
         compteur =+1;
         if (compteur %3 == 0)
         {
            //sortie << mot << " ";
         }
         if (compteur %3 == 1)
         {
            ciel.rightascension = atoi(mot.c_str());
         }
         if (compteur %3 == 2)
         {
            ciel.declination = atoi(mot.c_str());

            changementRepere(*sol->latitude, *sol->longitude, ciel.rightascension, ciel.declination);

            int Zone = long2UTM(sol.longitude);
            double _meridian = meridian(Zone);

            plan = forward(sol, _meridian);

            /*
            ostringstream X;
            ostringstream Y;
            X << &plan.x;
            Y << &plan.y;
            string _X = X.str();
            string _Y = Y.str();
            sortie << _X << " " << _Y << '\n';
            */
        }

    } // while
}






int main(){

    ofstream sortie("../Rendu/CatalogueProjete.txt");
    if(!sortie)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
	return -1;
    }

    ifstream catalogue("src/Cat.txt");
    if (!catalogue)
    {
        std:cerr<<"Cannot open the input file."<<std::endl; 
    return -1;
    }
    else 
    {
        projection(*catalogue, *sortie);
    } //

    return 0;
}








