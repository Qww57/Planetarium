#include "GeographicLib/TransverseMercator.hpp"
#include <fstream>
#include <string>

using namespace std;
using namespace GeographicLib;


/// Définition des structures

struct positionTerrestre{
    double latitude; // en degrés
    double longitude; // en degrés
};


struct positionCelestre{
    double rightascension; // en heures sidérales : 1 heure = 15°
    double declination;  // en heures sidérales : 1 heure = 15°
};

struct positionPlan{
    double x;
    double y;
};

/// Définition des fonctions de 

double enRadians (double angle);

void changementRepere (double &lat, double &longitude, double alpha, double delta);

positionTerrestre reverse(positionPlan in, double meridian);

void projection(ifstream &catalogue, ofstream &fichier);

positionPlan forward(positionTerrestre in);

double meridian(int zone);
