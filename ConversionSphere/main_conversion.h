#include "GeographicLib/TransverseMercator.hpp"

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

float enRadians (float angle);

void changementRepere(float &lat, float &long, float alpha, float delta);

positionTerrestre reverse(positionPlan in);

positionPlan forward(positionTerrestre in);

double decoupage (positionTerrestre in);
