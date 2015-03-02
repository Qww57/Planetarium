/**
 * \file writeText.cpp
 * \brief programme permettant d'écrire les informations relatives aux étoiles dans un fichier texte
 * \author Quentin.T
 * \version 0.1
 * \date 2 Mars 2015
 *
 *
 */

#include <iostream>
#include <fstream>
#include "detection_etoiles.h"
#include "writeText.h"

using namespace std;

void writeExplain(){
    ofstream fs("stars-explain.txt");
    if(!fs)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
    }
    fs << "Number of stars " << '\n';
    fs << "Height of the picture, width of the picture:" << '\n';
    fs << "Position x, position y, starHeight, starWidth " <<'\n';
    fs << "Position x, position y, starHeight, starWidth " <<'\n';
    fs << "ETC" << '\n';
}

void writeText(Mat *image, infosetoiles etoiles){
    ofstream fs("stars.txt");
    if(!fs)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
    }
    fs << etoiles.starPosition.size()  << '\n' ;
    fs << image->rows << " " << image->cols << '\n';
    for (int i = 0; i < etoiles.starPosition.size(); i++)
    {
        fs << etoiles.starPosition[i].x << " "
            << etoiles.starPosition[i].y << " "
            << etoiles.starHeight[i] << " "
            << etoiles.starWidth[i] << " " <<'\n';
    }
    writeExplain();
}
