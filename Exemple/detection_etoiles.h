/**
 * \file detection_etoiles.h
 * \brief programme de detection des boules
 * \author Quentin.T
 * \version 0.1
 * \date 21 février 2015
 *
 *
 */

#ifndef DETECTION_ETOILES_H
#define DETECTION_ETOILES_H

#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include "star.h"

using namespace cv;
using namespace std;


struct infosetoiles{
    vector<Point> starPosition;
    vector<int> starHeight;
    vector<int> starWidth;
};

void clearInfosetoiles(infosetoiles *etoiles);

std::vector<star*> starDetection_callback(cv::Mat img, infosetoiles *etoiles);

// void etoileDetection_createtrackbar();

void numberPrint(int number, infosetoiles etoiles);

void help();

#endif // DETECTION_ETOILES_H
