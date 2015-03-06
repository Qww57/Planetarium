/**
 *  \file testRDM.h
 * \brief programme permettant de tester le code RRDM
 * \author Quentin.T
 * \version 0.1
 * \date 4 mars 2015
 *
 *
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "detection_etoiles.h"

using namespace cv;

 Mat initialisation(Mat *imgOriginale);

 void test(Mat *imgOriginal, infosetoiles *etoiles, Mat *imgSmall, infosetoiles *etoilesSmall);

 void TestwriteText(Mat *image, infosetoiles etoiles, Mat *imgSmall, infosetoiles etoilesSmall);
