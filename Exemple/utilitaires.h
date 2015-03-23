/**
*
*   \file utilitaires.h
*   \brief déclarations de fonctions utiles
*   \author Valentin LIEVIN
*   \date 17 mars 2015
*

*
**/


#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include "star.h"

// return the shorter distance between a star and a point
int shorterDistance(std::vector<star*>, int t_x, int t_y);

// display a label with text
void set_label(cv::Mat& im, cv::Rect r, const std::string label);

#endif //UTILITAIRES_H
