/**
 * \file MainWindow.h
 * \brief fonction principale : permet de lire un ensemble de fichier NOMAD pour construire notre propre catalogue
 * \author Valentin Liévin
 * \version 0.1
 * \date 6 mars 2015
 *
 *
 */

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QDir>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>

#include <iostream>

#include "mainwindow.h"
#include "structures.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    QLabel P("Hello World", &w);
    w.show();
*/
    vector<StarData*> result;
    vector<StarData*> tmp;
    //result = readNomadFile("0250_nomad.txt");

    vector<string> filesNames;

    ///search files in directory
    QCoreApplication app(argc, argv);
        QDir dir("D:\\code\\Planetarium\\CatalogMaker\\nomad");
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        //dir.setSorting(QDir::Size | QDir::Reversed);
        //on parcourt les fichiers par taille décroissante
        dir.setSorting(QDir::Size );

        QFileInfoList list = dir.entryInfoList();
        std::cout << "     Bytes Filename" << std::endl<<endl;
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            //std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
                                                    //.arg(fileInfo.fileName()));
            //std::cout << std::endl;
            filesNames.push_back(fileInfo.fileName().toUtf8().constData());
        }
    ///end

    int m = 0;

    ///read nomad files
    for (int i = 0; i<filesNames.size(); i ++)
    {
        //cout << " file name : "<< filesNames.at(i) << endl;
        tmp = readNomadFile("D:\\code\\Planetarium\\CatalogMaker\\nomad\\"+filesNames.at(i));
        result.reserve(tmp.size() + result.size());
        result.insert(result.end(), tmp.begin(), tmp.end());
        tmp.clear();

        // test to know if we write in the file
         if (i==600 || i==1200 || i == filesNames.size()-1 )
         {
             ///writing in file
             QFile file;
                cout << "start writing : cat" << m<<endl<< "--> result size : " << result.size() << endl;
             if(m==0)
                file.setFileName("D:\\code\\Planetarium\\CatalogMaker\\projectCatalog\\cat0.txt");
             else if (m==1)
                file.setFileName("D:\\code\\Planetarium\\CatalogMaker\\projectCatalog\\cat1.txt");
             else if(m==2)
                file.setFileName("D:\\code\\Planetarium\\CatalogMaker\\projectCatalog\\cat2.txt");

             file.open(QIODevice::WriteOnly | QIODevice::Text);
             QTextStream cat(&file);
             for (int j = 0; j< result.size(); j ++)
             {
                 //string tmp = result[i].ID ;
                 cat << result.at(j)->ID.c_str() << " " << result.at(j)->RA << " " << result.at(j)->DEC << endl;
                 //cat<<tmp.c_str() << i <<endl;

                 ///free memory
                 delete result.at(j);
             }
             // optional, as QFile destructor will already do it:
             file.close();
             cout << "end writing : cat" << m <<endl;
             result.clear();
             m++;
         }
    }

    /*///writing last file
             QFile file("D:\\code\\Planetarium\\CatalogMaker\\projectCatalog\\cat2.txt");
                file.open(QIODevice::WriteOnly | QIODevice::Text);
                QTextStream cat(&file);
                for (int j = 0; j< result.size(); j ++)
                {
                    //string tmp = result[i].ID ;
                    cat << result.at(j).ID.c_str() << " " << result.at(j).RA << " " << result.at(j).DEC << endl;
                    //cat<<tmp.c_str() << i <<endl;
                }
                // optional, as QFile destructor will already do it:
                file.close();
    */

    /*
    ///  DEBUG
    cout << endl<<"#### result size : "<< result.size()<< endl<<endl;
    cout << "n°130 : "<<endl
         << "ID : " << result[129].ID << endl;
         //<< " BCTYM : " << result[129].BCTYM << endl<<
            cout <<"  |  RA : " << result[129].RA << " DEC : " << result[129].DEC <<endl;
         //<< " r : " << result[129].r <<endl<< " sRA : " << result[129].sRA << " sDEC : "<< result[129].sDEC << " EpRA : " << result[129].EpRA << " EpDEC : " << result[129].EpDEC <<endl
         //<< " pm RA : " << result[129].pmRA << " pmDEC : " << result[129].pmDEC <<endl<< " spRA : "<< result[129].spRA << " spDEC : "<<result[129].spDEC <<endl
         //<< " BmagR : " << result[129].BmagR <<endl
         cout << " VmagR : " << result[129].VmagR << "  VmagRpuissance : " << result[129].VmagRpuissance << endl;
         //<< " RmagR : "<< result[129].RmagR<<endl
         //<< " Jmag : " << result[129].Jmag << " Hmag : " << result[129].Hmag << " Kmag : " << result[129].Kmag<<endl
         //<< "is Recommended :" << result[129].Recommended
         cout<<endl;
    /// End DEBUG
    /// */




    //return a.exec();

    return 0;
}
