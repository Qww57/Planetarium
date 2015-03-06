/**
 *  \file testRDM.cpp
 * \brief programme permettant de tester le code RRDM
 * \author Quentin.T
 * \version 0.1
 * \date 4 mars 2015
 *
 *
 */

#include <fstream>
#include <iostream>

#include "testRRDM.h"


using namespace cv;

using namespace std;

Mat initialisation(Mat *imgOriginale){

    srand(time(NULL));
    
    if (imgOriginale->cols != 0) 
    {
    	int x = rand()%(imgOriginale-> cols/2);
    	int y = rand()%(imgOriginale-> rows/2);
    
    	int largeur = rand()%(imgOriginale->cols/2);
   	int longueur = rand()%(imgOriginale->rows/2);

    	return Mat(*imgOriginale, Rect( x, y, largeur, longueur));
    }
    else
    {
	cout << "Exception : image nulle " << endl;	
	return *imgOriginale;
    }
}

void test(Mat *imgOriginal, infosetoiles *etoiles, Mat *imgSmall, infosetoiles *etoilesSmall){

    starDetection_callback(*imgOriginal, etoiles);
    starDetection_callback(*imgSmall, etoilesSmall);

    //namedWindow( "cut");
    //imshow("cut", *imgSmall);
    //namedWindow( "original");
    //imshow("original", *imgOriginal);
}

void TestwriteText(Mat *image, infosetoiles etoiles, Mat *imgSmall, infosetoiles etoiles2){
    ofstream fs("../Textes/stars-ref.txt");

    if(!fs)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
    }
    fs << "0 0 " << image->rows << " " << image->cols << '\n';
    fs << etoiles.starPosition.size()  << '\n' ;
    for (int i = 0; i < etoiles.starPosition.size(); i++)
    {
        fs << etoiles.starPosition[i].x << " "
            << etoiles.starPosition[i].y << " "
            //<< etoiles.starHeight[i] << " "
            //<< etoiles.starWidth[i] << " "
            <<'\n';
    }

    ofstream fs2("../Textes/stars-part.txt");
    if(!fs2)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
    }

    fs2 << "0 0 " << imgSmall->rows << " " << imgSmall->cols << '\n';
    fs2 << etoiles2.starPosition.size()  << '\n' ;

    for (int i = 0; i < etoiles2.starPosition.size(); i++)
    {
        fs2 << etoiles2.starPosition[i].x << " "
            << etoiles2.starPosition[i].y << " "
            //<< etoiles2.starHeight[i] << " "
            //<< etoiles2.starWidth[i] << " "
            <<'\n';
    }
}
