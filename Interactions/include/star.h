/**
*
*   \file star.h
*   \brief déclaration de la classe star
*   \author Valentin LIEVIN
*   \date 17 mars 2015
*

*
**/

#ifndef STAR_H
#define STAR_H

#include <iostream>
#include <time.h>
#include <vector>
#include <math.h>


#include "opencv/highgui.h"
//#include "opencv/cv.h"


class star
{
    public:
        star();
        star(double tx , double ty);
        virtual ~star();

        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Gety() { return y; }
        void Sety(double val) { y = val; }
        std::string GetID() { return ID; }
        void SetID(std::string val) { ID = val; }

        void Afficher(cv::Mat img);
        void AfficherSelected(cv::Mat img);
        float GetDistance(int target_x, int target_y);

    private:
        double x;
        double y;
        std::string ID;
};

#endif // STAR_H
