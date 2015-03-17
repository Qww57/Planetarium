/**
 * \file MainWindow.h
 * \brief définition d'une classe mainwindow (inutile pour le moment)
 * \author Valentin Liévin
 * \version 0.1
 * \date 6 mars 2015
 *
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
