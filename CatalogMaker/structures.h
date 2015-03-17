/**
 * \file structure.h
 * \brief défintion de la structure de données starData
 * \author Valentin Liévin
 * \version 0.1
 * \date 6 mars 2015
 *
 *
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
   source : http://www.nofs.navy.mil/nomad/nomad_readme.html
   ( 1)   RA at 2000.0 in integer 0.001 arcsec
   ( 2)   SPD at 2000.0 in integer 0.001 arcsec
   ( 3)   std. dev. of RA*COS(dec) in integer 0.001 arcsec at central epoch
   ( 4)   std. dev. of SPD in integer 0.001 arcsec at central epoch
   ( 5)   proper motion of RA*COS(dec) in integer 0.0001 arcsec/year
   ( 6)   proper motion of SPD in integer 0.0001 arcsec/year
   ( 7)   std. dev. of (5) in integer 0.0001 arcsec/year
   ( 8)   std. dev. of (6) in integer 0.0001 arcsec/year
   ( 9)   central epoch of RA in integer 0.001 year
   (10)   central epoch of SPD in integer 0.001 year
   (11)   B magnitude in integer 0.001 mag
   (12)   V magnitude in integer 0.001 mag
   (13)   R magnitude in integer 0.001 mag
   (14)   J magnitude in integer 0.001 mag
   (15)   H magnitude in integer 0.001 mag
   (16)   K magnitude in integer 0.001 mag
   (17)   USNO-B1.0 ID integer
   (18)   2MASS ID integer
   (19)   YB6 ID integer
   (20)   UCAC-2 ID integer
   (21)   Tycho2 ID integer
   (22)   flags integer
**/


struct StarData { // permet d'enregistrer les données pertinentes d'une étoiles
    string ID;
    //string BCTYM;// ???
    double RA;//the Right Ascension of the object in hours or degrees. The epoch and equinox are those given in the file header.
    //The default is equinox and epoch J2000.0.
    double DEC; //the Declination of the object in degrees.
    //The epoch and equinox are those given in the file header. The default is equinox and epoch J2000.0.

/* pas utile pour le moment
    char r; // ???
    double sRA;  //the error in the RA position. This is given in integer milli-arcseconds. The error is given at the RA Mean Epoch.
    double sDEC;

    double EpRA;//this is the mean epoch of all the observations that went into determining the RA position of this object. This is given in decimal years.
    double EpDEC; //this is the mean epoch of all the observations that went into determining the DEC position of this object. This is given in decimal years.

    double pmRA;
    double pmDEC;
    double spRA;
    double spDEC;

    string BmagR;
    double VmagR; //visual magnitude number
    char VmagRpuissance;//visual magnitude letter
    string RmagR;

    string Jmag;
    string Hmag;
    string Kmag;
*/
    //bool Recommended;



    //double sDE; // the error in the DEC position. This is given in integer milli-arcseconds. The error is given at the DEC Mean Epoch.
    //double MuRa ; //the proper motion in RA. This is given in angular velocity units of milli-arcseconds per year. [This equals MuRA = d(RA)/dt x cos(DEC)]


};

std::vector<StarData *> readNomadFile(string path);

std::string GetDataUntilSymbol(string& source, char symbol);

#endif // STRUCTURES_H

