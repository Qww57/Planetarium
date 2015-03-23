/**
*
*   \file utilitaires.cpp
*   \brief déclarations de fonctions utiles
*   \author Valentin LIEVIN
*   \date 17 mars 2015
*

*
**/

#include "utilitaires.h"
#include <limits>

using namespace std;

int shorterDistance(vector<star*> stars, int t_x, int t_y)
{
    int m = -1;
    int d;
    float tmp = 100000000;
    //int infini = std::numeric_limits<int>::max();
    for (int i = 0; i< stars.size(); i++)
    {
        d = stars.at(i)->GetDistance(t_x,t_y);
        if ( d < tmp)
        {
            m = i;
            tmp = d;
        }
    }
    return m;
}

void set_label(cv::Mat& im, cv::Rect r, const std::string label)
{
    int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.5;
    int thickness = 1;
    int baseline = 0;

    cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
    cv::Point pt(r.x + (r.width-text.width)/2, r.y + (r.height+text.height)/2);

    cv::rectangle(
        im,
        pt + cv::Point(0, baseline),
        pt + cv::Point(text.width, -text.height),
        CV_RGB(50,50,50), CV_FILLED
    );

    cv::putText(im, label, pt, fontface, scale, CV_RGB(200,200,200), thickness, CV_AA);
}
