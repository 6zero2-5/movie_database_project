//
//  main.cpp
//  Data_Structures_Final_Project
//
//  Created by Eric Tyson on 11/27/20.
//

#include "actorActress.h"
#include "functions.h"
#include "movie.h"

using namespace std;

int main()
{
	//create appropriate data structures and read in data
	vector<ActorActress> actorActressArray;
	vector<Movie> pictureArray;
	actorActressDatabase(actorActressArray);
	pictureDatabase(pictureArray);
	//***************************************************
	
	//greeting
	cout << "Welcome to the movie database!" << endl;
	
	//main menu selection
	char choice;
	choice = mainMenu();
	do
	{
		switch(toupper(choice))
		{
			case 'A':
				addRecord(actorActressArray, pictureArray);
				break;
			case 'B':
				//modify function will be run from within the search database function
				searchDatabase(actorActressArray, pictureArray);
				break;
			case 'C':
				sortByUserChoice(actorActressArray, pictureArray);
				break;
			case 'D':
				searchDatabase(actorActressArray, pictureArray);
				break;
			case 'E':
				writeToCSV(actorActressArray, pictureArray);
				break;
			case 'F':
				cout << "Goodbye!" << endl;
				exit(-1);
			default:
				cout << "Not sure what to do with that. Try another choice:" << endl;
				break;
		}
		choice = mainMenu();
	}while(toupper(choice) != 'F');
	return 0;
}

/*
 To Do:
 **KEY to add to final project: I edited the actor-actress database because of the comma in three of the names (cuba gooding jr; luiis gossett; and howard rollins). This won't work for other databases; but isn't the first job of a data analyst to clean the database?
 Generally error check as much as you can (theres a lot of menu options and switch statements that would cause problems)
 Modify function done; but I have not found a way to add the new record back into the orginal database
 Done?
 */
