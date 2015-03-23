/**
 * \file detection_etoiles.cpp
 * \brief programme de detection des étoiles à partir de photos
 * \author Quentin.T
 * \version 0.1
 * \date 21 février 2015
 *
 *
 */


///@todo: faire mieux apparaitre les étoiles en rouge sur le blanc.


#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>

#include "detection_etoiles.h"
#include "star.h"

using namespace cv;
using namespace std;

int max_BINARY_value = 255;
int threshold_value = 200;
int threshold_type = 0;

int sigmaX = 0;
int sigmay = 0;

int canny1 = 0;
int canny2 = 50;
int canny3 = 5;

void help(){
    cout << endl <<  "HELP - Command list : " << endl;
    cout << " - UP : increase the threshold value " << endl;
    cout << " - DOWN : decrease the threshold value " << endl;
    cout << " - S : save the data in the file 'stars.txt' " << endl;
    //cout << " - U : save the date in a .txt file, you can choose the name " << endl;
    cout << " - ESC or Q : quit the application " << endl << endl;
}

/*
    CV_RETR_EXTERNAL retrieves only the extreme outer contours. It sets hierarchy[i][2]=hierarchy[i][3]=-1 for all the contours.
    CV_RETR_LIST retrieves all of the contours without establishing any hierarchical relationships.
    CV_RETR_CCOMP retrieves all of the contours and organizes them into a two-level hierarchy. At the top level, there are external boundaries of the components. At the second level, there are boundaries of the holes.
        If there is another contour inside a hole of a connected component, it is still put at the top level.
    CV_RETR_TREE retrieves all of the contours and reconstructs a full hierarchy of nested contours. This full hierarchy is built and shown in the OpenCV contours.c demo.

    CV_CHAIN_APPROX_NONE stores absolutely all the contour points. That is, any 2 subsequent points (x1,y1) and (x2,y2) of the contour will be either horizontal, vertical or diagonal neighbors, that is, max(abs(x1-x2),abs(y2-y1))==1.
    CV_CHAIN_APPROX_SIMPLE compresses horizontal, vertical, and diagonal segments and leaves only their end points. For example, an up-right rectangular contour is encoded with 4 points.
    CV_CHAIN_APPROX_TC89_L1,CV_CHAIN_APPROX_TC89_KCOS applies one of the flavors of the Teh-Chin chain approximation algorithm. See [TehChin89] for details.
*/

void clearInfosetoiles(infosetoiles *etoiles){
    etoiles->starHeight.clear();
    etoiles->starPosition.clear();
    etoiles->starWidth.clear();
}


vector<star*> starDetection_callback(Mat img, infosetoiles *etoiles){
	
    
    clearInfosetoiles(etoiles);

    vector<star*> vecS;

    // Concersion du gris en image binaire
    Mat imgG, imgB, dst, cir;
    cvtColor( img, imgG, CV_BGR2GRAY );

    int height = img.rows;
    int width = img.cols;

    cir = Mat::zeros( height, width, CV_8UC3 );

    double max_BINARY = (double) max_BINARY_value;
    double threshold_double = (double) threshold_value;

    threshold(imgG, dst, threshold_double, max_BINARY,threshold_type );

    Canny(dst, imgB, canny1, canny2, canny3 );

    Point offset = Point(0,0);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( imgB, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, offset);

    int ID = 0;

    /// on détecte le centre la hauteur et largeur des étoiles
    for( int i = 0; i< contours.size(); i++ ) // parcours de l'ensemble des contours fermés
    {
        Point center = Point(-1,-1);
        int maxwidth = contours[i][0].x;
        int maxheight = contours[i][0].y;
        int minwidth = contours[i][0].x;
        int minheight = contours[i][0].y;
        int starwidth= 0;
        int starheight = 0;

        for (int j = 0; j < contours[i].size(); j++) // parcours des points du contour
        {
            center.x += contours[i][j].x;
            center.y += contours[i][j].y;

            if (contours[i][j].x > maxwidth)
                maxwidth = contours[i][j].x;
            if (contours[i][j].y > maxheight)
                maxheight = contours[i][j].y;
            if (contours[i][j].x < minwidth)
                minwidth = contours[i][j].x;
            if (contours[i][j].y < minheight)
                minheight= contours[i][j].y;
        }

        starheight = maxheight - minheight -1;
        starwidth = maxwidth - minwidth -1;

        /// Calcul du centre de l'étoile
        if (contours[i].size() > 1)
        {
            center.x = center.x / contours[i].size() + 1;
            center.y = center.y / contours[i].size() + 1;
        }
        else {
            center = Point(-1,-1);
        }

	        
	
        if (center.x < cir.cols && center.y < cir.rows && center.x > 0 && center.y > 0 )
        {
            circle(cir, center, 1, Scalar(0,0,255), 1, 8, 0 );
            etoiles->starPosition.push_back(center);
            etoiles->starWidth.push_back(starwidth);
            etoiles->starHeight.push_back(starheight);
	    
	    stringstream ssID;
	    ssID << ID;
	    string strID = ssID.str();

	    star* newStar = new star();
            newStar->Setx(center.x);
	    newStar->Sety(center.y);
  	    newStar->SetID(strID);
	    vecS.push_back(newStar);
	    ID++;
        }
    }
    
    return vecS;
    //namedWindow( "result");
    //imshow("result", img + cir);
}


void numberPrint(int previous, infosetoiles etoiles){
    if (previous != etoiles.starPosition.size())
    {
        cout << "Nombre d'étoiles : "<< etoiles.starPosition.size() << endl;
    }
}


/*void etoileDetection_createtrackbar(){

    createTrackbar("Threshold_value", "result", &threshold_value, 255);
    //createTrackbar("Threshold_type", "cercles", &threshold_type, 4);
    //createTrackbar("canny1", "cercles", &canny1, 200);
    //createTrackbar("canny2", "cercles", &canny2, 2000);

}*/

