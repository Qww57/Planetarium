/**
*
*   \file correspondence.cpp
*   \date 19 mars 2015
*
**/

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <fstream>
#include <sstream>

#include "star.h"

vector<star*> correspondence(string correspondencefilename, string catalogfilename)
{
	vector<star*> starsList;

	ifstream correspondenceList(correspondencefilename.c_str(),ios::in);
	ifstream catalog(catalogfilename,ios::in);

	bool found = false;
	
	if(correspondenceList && catalog)
	{
		
		while(!correspondenceList.eof())
		{
			found=false;

			star* newStar = new star;
			
			double xRef,yRef,xImg,yImg;
			correspondenceList>>xRef>>yRef>>xImg>>yImg;
			
			newStar->Setx(xImg);
			newStar->Sety(yImg);

			while(found == false && !catalog.eof())
			{
				string ID;
				getline(catalog,ID,' ');
				double x,y;
				catalog>>x>>y;

				if(x==xRef && y==yRef)
				{
					newStar->SetID(ID);
					found = true;
					starsList.push_back(newStar);
				}
			}
		}
	}

	return starsList;
}

