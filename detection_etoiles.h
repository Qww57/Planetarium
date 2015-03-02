/**
 * \file etoiles_detection.h
 * \brief programme de detection des boules
 * \author Quentin.T
 * \version 0.1
 * \date 21 février 2015
 *
 *
 */

#ifndef DETECTION_ETOILES_H
#define DETECTION_ETOILES_H

#include "liste_etoile.h"

using namespace cv;
using namespace std;


struct infosetoiles{
    vector<Point> starPosition;
    vector<int> starHeight;
    vector<int> starWidth;
};

void clearInfosetoiles(infosetoiles *etoiles);

void starDetection_callback(cv::Mat img, infosetoiles *etoiles);

// void etoileDetection_createtrackbar();

void numberPrint(int number, infosetoiles etoiles);

void help();

#endif // DETECTION_ETOILES_H
