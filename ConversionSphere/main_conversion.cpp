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


/** @todo

    Code:
    - faire une fonction permettant de savoir où découper le ciel par rapport à la position de l'utilisateur
    - faire une fonction permettant de faire la projection d'une sphère sur un plan
    - faire une fonction permettant de lire les coordonnées à partir de stream pour tester

    Debug:
    - faire un truc permettant de vérifier graphiquement que tout va bien
        - faire une sphère
        - faire une fonction permettant de marquer les coordonnées terrestres sur la sphère
        - faire une fonction permettant de projeter les coordonnées dans le ciel sur la sphère
        => regarder si ça fonctionne bien avec la fonction DECOUPAGE
    - faire des tests sur la projection ?
        - texturer la sphère
        - faire la projection, voir le résultat
*/

// chercher le méridien de la zone en question....


/// MAIN

// utiliser geographiclib

// utiliser le cours de cral.univ-lyon1.fr avec tous les différents référentiels d'étoiles

/* Position des coordonnées au sol:
 * position géographique de Nantes en degrés décimaux
- définie par défaut pour les tests
- latitude: 47.21725
- longitude: -1.553360
*/

/* Système de coordonnées célestes
 * right ascension (ascension droite) est l'équivalent de la longitude, elle s'exprime en heures sidérales (15°C)
 * declination (déclinaison) est l'équivalent de la latittude : 0 pour un truc à l'équateur, 90 pour un truc au pôle nord - 90 pour un au sud
 * le point vernal est l'équivalent du méridien de Greenwich et sert de base => FAIRE DES RECHERCHES ICI
*/

/* Projection de la sphère:
 * plein d'algo existants de proj de sphères sous différents formats
 * choisir un truc qui conserve les angles et les formes géométriques
 * => projection UTM à partir de géographicLib
 *
 *
 * deux solutions:
 * - soit on découpe proprement à l'opposé de là où sont localisée les photos
 * soit on projete une fois et demi et on est sur de pas avoir coupé au mauvais endroit
*/


/// Définitions des fonctions de conversion

void changementRepere (float &lat, float &longitude, float alpha, float delta) //Passage des coordonnées célestes aux coordonnées géographiques
{
	float SinLat, CosLongXCosLat, SinLongXCosLat;
	
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

float enRadians (float angle)
{
	return (angle*PI)/180;
}

positionPlan forward(positionTerrestre in){
    positionPlan out;

    try {
        TransverseMercator proj(Constants::WGS84_a(), Constants::WGS84_f(), Constants::UTM_k0());
        // Alternatively: const TransverseMercator& proj = TransverseMercator::UTM;

        double lon0 = -75; // Central meridian for UTM zone 18
        {
            // Sample forward calculation
            cout << "Forward : ";
            double x, y;
            proj.Forward(lon0, in.latitude, in.longitude, x, y);
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
        double lon0 = -75; // Central meridian for UTM zone 18
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


/// Fonctions principales

// fonction permettant à partir de la position en entrée, en sortie on donne un découpage / concretement ce sera une valeur de l'ascension droite

/*double decoupage (positionTerrestre in){
    float out;

    // on part de l'entrée, on trouve l'équivalent en coordonnées dans le ciel
    positionCelestre pos;
    pos = conversionTerCel(in);

    // on va de l'autre coté de la map et on balance le truc
    out = pos.declination + 180/15; // conversion en heures sidérales
    return out;
}*/


/// MAIN

int main(){

    positionTerrestre Nantes;

    Nantes.latitude = 47.21725;
    Nantes.longitude = -1.53360;

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
        string identifiant;
	
	positionTerrestre in;
        positionPlan out;

        
	
        int compteur = 0;
        string mot;

        while (catalogue >> mot) 
        {
             compteur =+1;
             if (compteur %3 == 0)
	     {
                identifiant = mot;
                sortie << identifiant << " ";
             }
             if (compteur %3 == 1)
             {
                in.latitude = atoi(mot.c_str());                	
             }
             if (compteur %3 == 2)
             {
                in.longitude = atoi(mot.c_str());
                out = forward(in);
                sortie << out.x << " " << out.y<< endl;
             }

        } // while
    } // else

    // positionPlan nantes = forward(Nantes);

    return 0;
}


int maintest() {

    cout << "Hello world" << endl;

    positionTerrestre Nantes;

    Nantes.latitude = 47.21725;
    Nantes.longitude = -1.53360;


    try {
        TransverseMercator proj(Constants::WGS84_a(), Constants::WGS84_f(), Constants::UTM_k0());
        // Alternatively: const TransverseMercator& proj = TransverseMercator::UTM;
        double lon0 = -75; // Central meridian for UTM zone 18
        {
            // Sample forward calculation
            cout << "Forward : ";
            double lat = 40.3, lon = -74.7; // Princeton, NJ
            double x, y;
            proj.Forward(lon0, lat, lon, x, y);
            cout << x << " " << y << "\n";
        }
        {
            // Sample reverse calculation
            cout << "Reverse : ";
            double x = 25e3, y = 4461e3;
            double lat, lon;
            proj.Reverse(lon0, x, y, lat, lon);
            cout << lat << " " << lon << "\n";
        }
    }
    catch (const exception& e)
    {
        cerr << "Caught exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}







