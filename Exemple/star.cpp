/**
*
*   \file star.cpp
*   \brief déclarations de fonctions utiles
*   \author Valentin LIEVIN
*   \date 17 mars 2015
*

*
**/

#include "star.h"

using namespace cv;

star::star()
{
    //ctor
}

star::star(double tx , double ty)
{
    x = tx;
    y = ty;
}

star::~star()
{
    //dtor
}


void star::Afficher(cv::Mat img)
{
    circle( img,Point(x,y),1,Scalar( 0, 100, 255 ),-1,CV_AA);
}

void star::AfficherSelected(cv::Mat img)
{
    circle( img,Point(x,y),5,Scalar( 150, 150, 150 ),1,CV_AA);
}

float star::GetDistance(int target_x, int target_y)
{
     return sqrt((x-target_x)*(x-target_x)+(y-target_y)*(y-target_y));
}
