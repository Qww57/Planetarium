#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct StarData { // permet d'enregistrer les données pertinentes d'une étoiles
    string ID;
    string BCTYM;// ???
    double RA;//the Right Ascension of the object in hours or degrees. The epoch and equinox are those given in the file header.
    //The default is equinox and epoch J2000.0.
    double DEC; //the Declination of the object in degrees.
    //The epoch and equinox are those given in the file header. The default is equinox and epoch J2000.0.

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

    bool Recommended;



    double sDE; // the error in the DEC position. This is given in integer milli-arcseconds. The error is given at the DEC Mean Epoch.
    double MuRa ; //the proper motion in RA. This is given in angular velocity units of milli-arcseconds per year. [This equals MuRA = d(RA)/dt x cos(DEC)]


};

std::vector<StarData> readNomadFile(string path);

std::string GetDataUntilSymbol(string& source, char symbol);

#endif // STRUCTURES_H

