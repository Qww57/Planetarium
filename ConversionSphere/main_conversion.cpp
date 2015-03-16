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
#include <string>
#include <iomanip>
#include "GeographicLib/TransverseMercator.hpp"

#include "main_conversion.h"

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

    positionPlan nantes = forward(Nantes);

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






