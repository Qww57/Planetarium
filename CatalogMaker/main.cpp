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
    vector<StarData> result;
    vector<StarData>tmp;
    result = readNomadFile("0250_nomad.txt");

    vector<string> filesNames;

    ///search files in directory
    QCoreApplication app(argc, argv);
        QDir dir("D:\\code\\Planetarium\\CatalogMaker\\nomad");
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Size | QDir::Reversed);

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


    ///read nomad files
    for (int i = 0; i<filesNames.size(); i ++)
    {
        //cout << " file name : "<< filesNames.at(i) << endl;
        tmp = readNomadFile("D:\\code\\Planetarium\\CatalogMaker\\nomad\\"+filesNames.at(i));
        result.reserve(tmp.size() + result.size());
        result.insert(result.end(), tmp.begin(), tmp.end());
        tmp.clear();
    }




    ///  DEBUG
    cout << "#### result size : "<< result.size()<< endl<<endl;
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

    ///writing our file
         QFile file("D:\\code\\Planetarium\\CatalogMaker\\projectCatalog\\cat.txt");
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream cat(&file);
            for (int i = 0; i< result.size(); i ++)
            {
                //string tmp = result[i].ID ;
                cat << result.at(i).ID.c_str() << "|" << result.at(i).RA << "|" << result.at(i).DEC << endl;
                //cat<<tmp.c_str() << i <<endl;
            }
            // optional, as QFile destructor will already do it:
            file.close();


    //return a.exec();

    return 0;
}
