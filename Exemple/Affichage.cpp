/**
*
*   \file main.cpp
*   \brief fonction principale du bloc interactions : un clic permet de sélectionner l'étoile la plus proche
*   \author Valentin LIEVIN
*   \date 17 mars 2015
*
*
**/


/// NB : pour inclurer les librairies : voir le .pro

#include "include/star.h"
#include "include/utilitaires.h"

using namespace std;
using namespace cv;

cv::Mat image;

//window size
int w = 1000;

/**
 * \fn void onMouse( int event, int x, int y, int, void* )
 * \brief gestion de la souris
 *
 */
void onMouse( int event, int x, int y, int, void* );

/** variables globales (utiles pour la gestion de la souris)**/
bool clic; // vrai lorsqu'il y a une clic

int mouse_x,mouse_y;


int main(int argc, char **argv){

    int number_of_stars = 10000;


    bool bcontinue = true; // booléen utilisé pour quitter la boucle principale
    srand(time(NULL)); // initialisation de rand
    bool clic = false;

    mouse_x = w/2 ,mouse_y= w/2;
    star s(mouse_x, mouse_y);

    vector<star*> stars;
    for (int i = 0; i<number_of_stars; i++)
    {
        star *stmp = new star(rand()%w, rand()%w);
        stringstream id;
        id << rand();
        string id2 = id.str();
        stmp->SetID(id2);
        stars.push_back(stmp);
    }

    int m =-1;



    while(bcontinue)
    {
        system("clear");

        char nomAffichage[] = " Affichage du billard ";

          // on crée une image vide -> à remplacer par l'image de la webcam
        image =  Mat::zeros( w, w, CV_8UC3 );

        //star s(mouse_x, mouse_y);
        //s.Afficher(image);
        //s.AfficherSelected(image);

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
                    bcontinue = false;
                    break;
            }

    }



  return 0;

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
