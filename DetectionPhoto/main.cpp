/**
 * \file main.cpp
 * \brief Programme principal
 * \author Quentin.T
 * \version 0.1
 * \date 21 février 2015
 *
 *
 *
 */


#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include "detection_etoiles.h"
#include "writeText.h"
#include "testRRDM.h"

using namespace cv;
using namespace std;

#define KEY_UP 65362
#define KEY_DOWN 65364


/// Définir test à 1 pour générer des fichiers pour tester le code RRDM
#define TEST 1


extern int threshold_value;

/// MAIN

int main( int argc, char** argv){

    Mat imgOriginal;

    string path = "../Etoiles/etoile3.jpg";
    imgOriginal = imread(path, CV_LOAD_IMAGE_COLOR);

    if(! imgOriginal.data ) // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    infosetoiles etoiles;
    bool continu = true;
    int previousnumber = 0;

    Mat imgSmall = initialisation(&imgOriginal);
    infosetoiles etoilesSmall;

    if (TEST == 1)
	cout << "Générer tests pour RRDM" << endl;	
 

    while (continu)
    {
        starDetection_callback(imgOriginal, &etoiles);

        numberPrint(previousnumber, etoiles);
        previousnumber = etoiles.starPosition.size();

        if (TEST == 1)
            test(&imgOriginal, &etoiles, &imgSmall, &etoilesSmall);

        int key = waitKey(30);
        // if( key != -1) {cout << key << endl;}

        switch (key)
        {
            case 49:
                cout << "LOAD: 1 key is pressed by user, image 1 is loaded" << endl;
                path = "../Etoiles/etoile1.jpg";
                imgOriginal = imread(path, CV_LOAD_IMAGE_COLOR);
            break;

            case 50:
                cout << "LOAD: 2 key is pressed by user, image 2 is loaded" << endl;
                path = "../Etoiles/etoile2.jpg";
                imgOriginal = imread(path, CV_LOAD_IMAGE_COLOR);
            break;

            case 51:
                cout << "LOAD: 3 key is pressed by user, image 3 is loaded" << endl;
                path = "../Etoiles/etoile3.jpg";
                imgOriginal = imread(path, CV_LOAD_IMAGE_COLOR);
            break;

            case 27:
                cout << "EXIT: esc key is pressed by user" << endl;
                imgOriginal.release();
                continu = false;
            break;

            case 'q':
                cout << "EXIT: q key is pressed by user" << endl;
                imgOriginal.release();
                continu = false;
            break;

            case 's':
                cout << "SAVE: s is pressed by user, saving the data" << endl;
                if (TEST == 1){
                    TestwriteText(&imgOriginal, etoiles, &imgSmall, etoilesSmall);
                }
                else {
                    writeText(&imgOriginal, etoiles);
                }
            break;

            case 'h':
                cout << "HELP: h is pressed by user, help menu printed" << endl;
                help();
            break;

            case KEY_UP:
                if (threshold_value < 255)
                    threshold_value = threshold_value +1;
                cout << "UP: Key Up is pressed by user, threshold value + 1 : " << threshold_value << " / 255 " << endl;
            break;

            case KEY_DOWN:
                if (threshold_value > 0)
                    threshold_value = threshold_value -1;
                cout << "Down: Key down is pressed by user, threshold value - 1 : " << threshold_value << " / 255 " << endl;
            break;

            case 'n':
                if (TEST == 1)
                {
                    cout << "NEW: n is pressed by user, new cut picture :";
                    imgSmall.release();
                    imgSmall = initialisation(&imgOriginal);
                    cout << "New dimensions : " << imgSmall.cols << " " << imgSmall.rows << endl;
                }
            break;
        }
    }
    return(0);
}









