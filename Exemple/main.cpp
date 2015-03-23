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
#include <vector>


#include "detection_etoiles.h"
#include "writeText.h"
#include "testRRDM.h"
#include "star.h"
#include "utilitaires.h"

using namespace cv;
using namespace std;

#define KEY_UP 65362
#define KEY_DOWN 65364

extern int threshold_value;

void onMouse( int event, int x, int y, int, void* );

/** variables globales (utiles pour la gestion de la souris)**/
bool clic; // vrai lorsqu'il y a une clic

int mouse_x,mouse_y;

/// MAIN

int main( int argc, char** argv){

    //window size
    int w = 1000;
    int m = 0;

    vector<star*> stars;

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
    //infosetoiles etoilesSmall;

    Mat image;

    stars = starDetection_callback(imgOriginal, &etoiles);

    while (continu)
    {
	system("clear");

        char nomAffichage[] = " Exemple ";

        // on crée l'image 
        image =  imgOriginal;

        for (int i = 0; i< stars.size(); i ++)
        {
            stars.at(i)->Afficher(image);
        }

        m = shorterDistance(stars, mouse_x,mouse_y);
        cout << m << endl;
        if (m>=0)
        {
            stars.at(m)->AfficherSelected(image);
        }

        set_label(image, cv::Rect(stars.at(m)->Getx()-80, stars.at(m)->Gety()+10, 160, 50),  stars.at(m)->GetID());

            //écriture et affichage de la nouvelle image

            namedWindow(nomAffichage);
            setMouseCallback( nomAffichage, onMouse, 0 );
            imshow( nomAffichage, image);
            //moveWindow( nomAffichage, 0, 0 );


            int key = cvWaitKey(20); // capture des événements claviers - (20) -> on attend 20ms

            //gestion des événements clavier
            switch(key)
            {
                    case(27):
                    continu = false;
                    break;
            }
    }
    return(0);
}

// gérer la souris
void onMouse( int event, int x, int y, int, void* )
{
    if  ( event == EVENT_LBUTTONDOWN )
    {

        clic = true;
        mouse_x = x;
        mouse_y = y;

    }
    else
    {
        clic = false;
    }


}







