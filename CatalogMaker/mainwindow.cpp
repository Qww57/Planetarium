/**
 * \file MainWindow.cpp
 * \brief définition d'une classe mainwindow (inutile pour le moment)
 * \author Valentin Liévin
 * \version 0.1
 * \date 6 mars 2015
 *
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
