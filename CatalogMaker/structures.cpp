/**
 * \file structure.cpp
 * \brief contient la fonction readNomadFile() permettant de lire un fichier texte nomad et retourne une structure starData
 * \author Valentin Liévin
 * \version 0.1
 * \date 6 mars 2015
 *
 *
 */

#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int i;

std::vector<StarData*> readNomadFile(string path)
{
    string line;
    vector<StarData*> result;

    ifstream myfile(path.c_str());
    if (myfile.is_open())
    {

       cout <<"[SUCCES] " << i<< "  open : " << path<<endl;
       i++;
       while(getline (myfile,line)) //on parcourt chaque ligne du fichier
       {

       if (line.c_str()[0] != '#' && line[line.length()-2]=='R') //s'il ne s'agit pas d'un commentaire (#) et si l'étoile est recommendée
       {
            //cout << "end line : " << line[line.length()-2]<<endl;
           //create a string vector by parse the line with |
           std::string delimiter = "|";
           vector<string> words;
           words.clear();
            int i = 0;
           size_t pos = 0;
           std::string token;
           //on sépare la ligne suivant les séparateurs |
           while ((pos = line.find(delimiter)) != std::string::npos ) {
               token = line.substr(0, pos);
               //std::cout <<" test : "<<i<<" : ~"<< token <<"~"<< std::endl;
               words.push_back(token);
               line.erase(0, pos + delimiter.length());
               i++;
           }


           //write starData
           StarData *tmp = new StarData;

           // 0 : ID
           tmp->ID = words.at(0);
           // 1 : BCTYM
           //tmp.BCTYM = words.at(1);
           // 2 : RA, DEC, r,sRA, sDEC

           //create a string vector by parse the line with ' '

           vector<string> words1;
           string word = words.at(2);
           delimiter = " ";
           //on sépare la ligne suivant les séparateurs " "
           while ((pos = word.find(delimiter)) != std::string::npos )
           {            
               token = word.substr(0, pos);
               if(token != "")
               {
                   words1.push_back(token);
                   //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< token<<"~ " << std::endl;
               }
               word.erase(0, pos + delimiter.length());


               }
               words1.push_back(word);
                //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< word<<"~ " << std::endl;

               //RA
               word = words1.at(0);
               //std::replace( word.begin(), word.end(), '.', ',');
               pos = (word.find("-"));
               tmp->RA = atof(word.substr(0,pos).c_str());
               word.erase(0, pos + 1);
               //DEC
               tmp->DEC = atof(word.c_str());

               //r
               //tmp.r = words1.at(1)[0];

               //sRA
               //tmp.sRA = atof(words1.at(2).c_str());

               //sRA
               //tmp.sDEC = atof(words1.at(3).c_str());

               //cout <<" RA : " << tmp.RA << " ||| RA : " << tmp.DEC<< " r : " << tmp.r << " sRA : " << tmp.sRA <<endl;


               // EpRA, EpDEC
               word = words.at(3);
               std::replace( word.begin(), word.end(), '.', ',');
               pos = (word.find(" "));
               //tmp.EpRA = atof(word.substr(0,pos).c_str());
               word.erase(0, pos + 1);
               //DEC
               //tmp.EpDEC = atof(word.c_str());
               //cout << " EpRA : "<<tmp.EpRA<< "  EpDEC : "<< tmp.EpDEC<<endl;

               // pmRA, pmDEC, spRA, spDEC

               words1.clear();
               word = words.at(4);
               replace( word.begin(), word.end(), '.', ',');
               delimiter = " ";
               //on sépare la ligne suivant les séparateurs " "
               while ((pos = word.find(delimiter)) != std::string::npos )
               {
                   token = word.substr(0, pos);
                   if(token != "")
                   {
                       words1.push_back(token);
                       //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< token<<"~ " << std::endl;
                   }
                   word.erase(0, pos + delimiter.length());


               }
               words1.push_back(word);
                //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< word<<"~ " << std::endl;
/*
                tmp.pmRA = atof(words1.at(0).c_str());
                tmp.pmDEC = atof(words1.at(1).c_str());
                tmp.spRA = atof(words1.at(2).c_str());
                tmp.spDEC = atof(words1.at(3).c_str());
*/
                //cout<< "pmRA : " << tmp.pmRA << " pmDEC : " << tmp.pmDEC << " spRA : " << tmp.spRA << " spDEC : "<< tmp.spDEC<< endl;

                // Bmag.r, Vmag.r, Rmag.r

                words1.clear();
                word = words.at(5);
                //replace( word.begin(), word.end(), '.', ',');
                delimiter = " ";
                //on sépare la ligne suivant les séparateurs " "
                while ((pos = word.find(delimiter)) != std::string::npos )
                {
                    token = word.substr(0, pos);
                    if(token != "")
                    {
                        words1.push_back(token);
                        //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< token<<"~ " << std::endl;
                    }
                    word.erase(0, pos + delimiter.length());


                }
                words1.push_back(word);
                 //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< word<<"~ " << std::endl;

                 //tmp.BmagR = words1.at(0);

                 //VmagR, VmagRpuissance
                 string vmagr = words1.at(1).substr(0, words1.at(1).length()-2);
                 //tmp.VmagR = atof(vmagr.c_str());
                 //tmp.VmagRpuissance = words1.at(1)[words1.at(1).length()-1];
                 float V = atof(vmagr.c_str());
                 char P = words1.at(1)[words1.at(1).length()-1];



                 //tmp.RmagR = words1.at(2);

                 //Jmag, Hmag, Kmag

                 words1.clear();
                 word = words.at(6);
                 //replace( word.begin(), word.end(), '.', ',');
                 delimiter = " ";
                 //on sépare la ligne suivant les séparateurs " "
                 while ((pos = word.find(delimiter)) != std::string::npos )
                 {
                     token = word.substr(0, pos);
                     if(token != "")
                     {
                         words1.push_back(token);
                         //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< token<<"~ " << std::endl;
                     }
                     word.erase(0, pos + delimiter.length());


                 }
                 words1.push_back(word);
                  //std::cout <<" test1 : "<<words1.size()-1<<" : ~"<< word<<"~ " << std::endl;

                  //tmp.Jmag = words1.at(0);
                  //tmp.Hmag = words1.at(1);
                  //tmp.Kmag = words1.at(2);

                  //recommended
/*
                  if (words.at(7).c_str()[0] == ' ')
                  {
                      tmp->Recommended = false;
                  }
                  else
                  {
                      tmp->Recommended = true;
                  }
*/
                  //cout << "recommended : " <<tmp.Recommended << endl;
                 if ( V > 17.0) //simple filter using the visual magnitude
                    result.push_back(tmp);

            }
       }
       myfile.close();

    }



    else
    {
        cout <<"[FAIL]  open : " << path<<endl;
    }

    return result;
}

