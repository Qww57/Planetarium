/**
 * \file writeText.h
 * \brief programme permettant d'écrire les informations relatives aux étoiles dans un fichier texte
 * \author Quentin.T
 * \version 0.1
 * \date 2 Mars 2015
 *
 *
 */

#ifndef WRITETEXT_H
#define WRITETEXT_H

#include "detection_etoiles.h"

void writeText(cv::Mat *image, infosetoiles etoiles);

void writeExplain();

#endif // WRITETEXT_H
