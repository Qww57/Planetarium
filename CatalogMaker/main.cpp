#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <iostream>

#include "structures.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLabel P("Hello World", &w);
    w.show();

    vector<StarData> result;
    result = readNomadFile("0250_nomad.txt");


    ///  DEBUG
    cout << "result size : "<< result.size()<< endl;
    cout << "n°130 : "<<endl
         << "ID : " << result[129].ID << endl
         << " BCTYM : " << result[129].BCTYM << "  |  RA : " << result[129].RA << " DEC : " << result[129].DEC <<endl
         << " r : " << result[129].r <<endl<< " sRA : " << result[129].sRA << " sDEC : "<< result[129].sDEC << " EpRA : " << result[129].EpRA << " EpDEC : " << result[129].EpDEC <<endl
         << " pm RA : " << result[129].pmRA << " pmDEC : " << result[129].pmDEC <<endl<< " spRA : "<< result[129].spRA << " spDEC : "<<result[129].spDEC <<endl
         << " BmagR : " << result[129].BmagR << " VmagR : " << result[129].VmagR << " RmagR : "<< result[129].RmagR<<endl
         << " Jmag : " << result[129].Jmag << " Hmag : " << result[129].Hmag << " Kmag : " << result[129].Kmag<<endl
         << "is Recommended :" << result[129].Recommended<<endl;
    /// End DEBUG


    //return a.exec();

    return 0;
}
