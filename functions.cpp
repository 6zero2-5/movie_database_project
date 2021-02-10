//
//  functions.cpp
//  Data_Structures_Final_Project
//
//  Created by Eric Tyson on 11/27/20.
//

#include "functions.h"
#include "movie.h"

using namespace std;

//main menu function.
char mainMenu()
{
	char choice;
	cout << "Main menu.\nPlease choose from the below choices: " << endl;
	
	cout << "A. Add Record" << endl
		 << "B. Modify Record" << endl
		 << "C. Sort Records" << endl
		 << "D. Search" << endl
		 << "E. Print File" << endl
		 << "F. Exit" << endl
		 << "> ";
	cin >> choice;
	
	return choice;
}

//add record function
void addRecord(vector<ActorActress>& aaVec, vector<Movie>& movieVec)
{
	//temp variables
	Movie tempMovie;
	ActorActress tempAA;
	string tempWord;
	
	//allow user to choose which database
	char again = 'Y'; //does user want to add multiple records?
	do
	{
		char choice;
		cout << "Which database would you like to add to?" << endl
			 << "A. Actor Actress Database" << endl
			 << "B. Movie Database" << endl
			 << "> ";
		cin >> choice;
		
		if (toupper(choice) == 'A')
		{
			cout << "Enter the year: ";
			cin.ignore();
			getline(cin, tempWord);
			tempAA.setYear(tempWord);
			cout << "Enter award: ";
			getline(cin, tempWord);
			tempAA.setAward(tempWord);
			cout << "Did they win? ";
			getline(cin, tempWord);
			tempAA.setWinner(tempWord);
			cout << "Actor/actress name: ";
			getline(cin, tempWord);
			tempAA.setName(tempWord);
			cout << "Film title: ";
			getline(cin, tempWord);
			tempAA.setFilm(tempWord);
			aaVec.push_back(tempAA);
			
			//sort database again
			sortByName(aaVec);
			
			cout << "Would you like to enter another record (Y or N)?";
			cin >> again;
		}
		else if (toupper(choice) == 'B')
		{
			cout << "Enter Movie title: ";
			cin.ignore();
			getline(cin, tempWord);
			tempMovie.setName(tempWord);
			tempWord.clear();
			cout << "Enter year: ";
			getline(cin, tempWord);
			tempMovie.setYear(tempWord);
			cout << "Enter nominations: ";
			getline(cin, tempWord);
			tempMovie.setNominations(tempWord);
			cout << "Enter rating: ";
			getline(cin, tempWord);
			tempMovie.setRating(tempWord);
			cout << "Enter duration: ";
			getline(cin, tempWord);
			tempMovie.setDuration(tempWord);
			cout << "Enter genre 1: ";
			getline(cin, tempWord);
			tempMovie.setGenre1(tempWord);
			cout << "Enter genre 2: ";
			getline(cin, tempWord);
			tempMovie.setGenre2(tempWord);
			cout << "Enter release: ";
			getline(cin, tempWord);
			tempMovie.setRelease(tempWord);
			cout << "Enter metacritic: ";
			getline(cin, tempWord);
			tempMovie.setMetacritic(tempWord);
			cout << "Enter synopsis: ";
			getline(cin, tempWord);
			tempMovie.setSynposis(tempWord);
			movieVec.push_back(tempMovie);
			
			//sort database again
			sortByFilm(movieVec);
			
			cout << "Would you like to add another record (Y or N)?";
			cin >> again;
		}
		else
		{
			cout << "I'm not sure what to do with that. Please enter a choice from the list." << endl;
		}
	}while(toupper(again) == 'Y');
}

void searchDatabase(vector<ActorActress>& aaVec, vector<Movie>& movieVec)
{
	//allow user to choose which database
	char choice;
	cout << "Which database would you like to search?" << endl
		 << "A. Actor Actress Database" << endl
		 << "B. Movie Database" << endl
		 << "> ";
	cin >> choice;
	
	if (toupper(choice) == 'A')
	{
		char corP;
		cout << "Would you like a complete search or a partial search?" << endl
		<< "A. Complete" << endl
		<< "B. Partial" << endl
		<< "> ";
		cin >> corP;
		
		switch(toupper(corP))
		{
			case 'A':
				actorActressCompleteSearch(aaVec);
				break;
			case 'B':
				actorActressPartialSearch(aaVec);
				break;
		}
	}
	if (toupper(choice) == 'B')
	{
		char corP;
		cout << "Would you like a complete search or a partial search?" << endl
		<< "A. Complete" << endl
		<< "B. Partial" << endl
		<< "> ";
		cin >> corP;
		
		switch(toupper(corP))
		{
			case 'A':
				movieCompleteSearch(movieVec);
				break;
			case 'B':
				moviePartialSearch(movieVec);
				break;
		}
	}
}

void sortByUserChoice(vector<ActorActress>& aaVec, vector<Movie>& movieVec)
{
	char choice;
	do
	{
		cout << "Which database would you like to sort by? " << endl
			 << "A: Actor Actress" << endl
			 << "B: Movie" << endl
			 << "> ";
		cin >> choice;
		
		switch(toupper(choice))
		{
			case 'A':
				sortAAChoice(aaVec);
				break;
			case 'B':
				sortMovieChoice(movieVec);
				break;
			default:
				cout << "I'm not sure what to do with that. Please choose an option from the list." << endl;
		}
	}while(toupper(choice) != 'A' && toupper(choice) != 'B');
}

bool wordMatch(string w1, string w2)
{
	//convert w1 to lower case
	for (int i = 0; i < w1.size(); i++)
		w1[i] = tolower(w1[i]);
	
	//convert w2 to lower case
	for (int i = 0; i < w2.size(); i++)
		w2[i] = tolower(w2[i]);
	
	return (w1 == w2) ? true : false;
}

bool partialMatch(string w1, string w2)
{
	for (int i = 0; i < w1.size(); i++)
		w1[i] = tolower(w1[i]);
	
	for (int i = 0; i < w2.size(); i++)
		w2[i] = tolower(w2[i]);
	
	return (w2.find(w1) != string::npos) ? true : false;
}

void writeToCSV(vector<ActorActress>& aaVec, vector<Movie>& movieVec)
{
	ofstream out1("newAA.csv");
	ofstream out2("newMovie.csv");
	
	out1 << "Film" << "," << "Award" << "," << "Name" << "," << "Year" << "," << "Winner" << endl;
	for (int i = 0; i < aaVec.size(); i++)
	{
		out1 << aaVec[i].getFilm() << "," << aaVec[i].getAward() << "," << aaVec[i].getName() << "," << aaVec[i].getYear() << "," << aaVec[i].getWinner() << endl;
	}
	
	out2 << "Title" << "," << "Year" << "," << "Nominations" << "," << "Rating" << "," << "Duration" << "," << "Genre1" << "," << "Genre2" << "," << "Release" << "," << "Metacritic" << "," << "Synopsis" << endl;
	
	for (int i = 0; i < movieVec.size(); i++)
	{
		out2 << movieVec[i].getName() << "," << movieVec[i].getYear() << "," << movieVec[i].getNominations() << "," << movieVec[i].getRating() << "," << movieVec[i].getDuration() << "," << movieVec[i].getGenre1() << "," << movieVec[i].getGenre2() << "," << movieVec[i].getRelease() << "," << movieVec[i].getMetacritic() << "," << movieVec[i].getSynopsis() << endl;
	}
}

//******* FUNCTIONS FOR THE ACTOR ACTRESS DATABASE *********
void sortByName(vector<ActorActress>& vec)
{
	sort(vec.begin(), vec.end());
}

//build the database
void actorActressDatabase(vector<ActorActress>& vec)
{
	ActorActress temp;
	//builds database by reading a csv and storing all information into a vector
	ifstream f("actor-actress.csv");
	string line; //for get line
	int count = 0; //to read specific items from the line
	
	while(getline(f,line))
	{
		stringstream s(line); //put line into string stream
		string word; //to parse string stream
		while(getline(s,word,','))
		{
			if (count == 0)
			{
				temp.setYear(word);
				count += 1;
				continue;
			}
			if (count == 1)
			{
				temp.setAward(word);
				count += 1;
				continue;
			}
			if (count == 2)
			{
				temp.setWinner(word);
				count += 1;
				continue;
			}
			if (count == 3)
			{
				temp.setName(word);
				count += 1;
				continue;
			}
			if (count == 4)
			{
				temp.setFilm(word);
				vec.push_back(temp);
				count = 0;
				break;
			}
		}
	}
	sortByName(vec);
}

vector<ActorActress> searchByName(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter a name: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (wordMatch(aaVec[i].getName(), word) == true)
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<ActorActress> searchByAward(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter an award: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (wordMatch(aaVec[i].getAward(), word) == true)
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<ActorActress> searchByYear(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter a year: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (wordMatch(aaVec[i].getYear(), word) == true)
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<ActorActress> searchByFilm(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter a year: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (wordMatch(aaVec[i].getFilm(), word) == true)
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

void sortAAChoice(vector<ActorActress>& aavec)
{
	char choice;
	do
	{
		cout << "Which field would you like to sort by? " << endl
		<< "A: Year" << endl
		<< "B: Award" << endl
		<< "C: Film" << endl
		<< "> ";
		cin >> choice;
		
		switch(toupper(choice))
		{
			case 'A':
				//all sorts (other than original name sort) done by insertion
				for (int i = 1; i < aavec.size(); i++)
				{
					ActorActress temp = aavec[i];
					int j = i - 1;
					while (j >= 0 && temp.getYear() <= aavec[j].getYear())
					{
						aavec[j+1] = aavec[j];
						j = j-1;
					}
					aavec[j+1] = temp;
				}
				break;
			case 'B':
				for (int i = 1; i < aavec.size(); i++)
				{
					ActorActress temp = aavec[i];
					int j = i - 1;
					while (j >= 0 && temp.getAward() <= aavec[j].getAward())
					{
						aavec[j+1] = aavec[j];
						j = j-1;
					}
					aavec[j+1] = temp;
				}
				break;
			case 'C':
				for (int i = 1; i < aavec.size(); i++)
				{
					ActorActress temp = aavec[i];
					int j = i - 1;
					while (j >= 0 && temp.getFilm() <= aavec[j].getFilm())
					{
						aavec[j+1] = aavec[j];
						j = j-1;
					}
					aavec[j+1] = temp;
				}
				break;
			default:
				cout << "I'm not sure what to do with that. Please choose an item from the list" << endl;
		}
	}while(toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C');
	cout << "Sorting finished! Returning to main menu." << endl;
}

void actorActressCompleteSearch(vector<ActorActress> aaVec)
{
	char choice;
	char again = 'Y';
	vector<ActorActress> temp;
	do
	{
		int flag = 0;
		cout << "What would you like to search by?" << endl
			 << "A: Name " << endl
			 << "B: Award " << endl
			 << "C: Year " << endl
			 << "D: Film " << endl
			 << "> ";
		
		cin >> choice;
		switch(toupper(choice))
		{
			case 'A':
				(flag == 0) ? temp = searchByName(aaVec) : temp = searchByName(temp);
				// possible modify function
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
			case 'B':
				(flag == 0) ? temp = searchByAward(aaVec) : temp = searchByAward(temp);
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
			case 'C':
				(flag == 0) ? temp = searchByYear(aaVec) : temp = searchByYear(temp);
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
			case 'D':
				(flag == 0) ? temp = searchByFilm(aaVec) : temp = searchByFilm(temp);
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
		}
	}while(toupper(again) == 'Y');
}

void actorActressPartialSearch(vector<ActorActress> aaVec)
{
	char choice;
	char again = 'Y';
	do
	{
		int flag = 0;
		vector<ActorActress> temp;
		cout << "What would you like to search by?" << endl
			 << "A: Name " << endl
			 << "B: Award " << endl
			 << "C: Year " << endl
			 << "D: Film " << endl
			 << "> ";
		
		cin >> choice;
		switch(toupper(choice))
		{
			case 'A':
				(flag == 0) ? temp = AApartialByName(aaVec) : temp = AApartialByName(temp);
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
			case 'B':
				(flag == 0) ? temp = AApartialByAward(aaVec) : temp = AApartialByAward(temp);
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
			case 'C':
				(flag == 0) ? temp = AApartialByYear(aaVec) : temp = AApartialByYear(temp);
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
			case 'D':
				(flag == 0) ? temp = AApartialByFilm(aaVec) : temp = AApartialByFilm(temp);
				if (temp.size() == 1)
				{
					modifyAA();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
		}
	}while(toupper(again) == 'Y');
}

vector<ActorActress> AApartialByName(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter your criteria: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (partialMatch(word,aaVec[i].getName()))
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<ActorActress> AApartialByAward(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter your criteria: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (partialMatch(word,aaVec[i].getAward()))
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<ActorActress> AApartialByYear(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter your criteria: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (partialMatch(word,aaVec[i].getYear()))
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<ActorActress> AApartialByFilm(vector<ActorActress> aaVec)
{
	string word;
	vector<ActorActress> temp;
	bool flag = true;
	cout << "Enter your criteria: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < aaVec.size(); i++)
	{
		if (partialMatch(word,aaVec[i].getFilm()))
		{
			temp.push_back(aaVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

void modifyAA()
{
	char modify;
	ActorActress tempAA;
	string word;
	cout << "Would you like to modify this entry (Y or N)?" << endl
		 << "> ";
	cin >> modify;
	
	if (toupper(modify) == 'Y')
	{
		cout << "New Name: ";
		cin.ignore();
		getline(cin, word);
		tempAA.setName(word);
		
		cout << "Award: ";
		getline(cin, word);
		tempAA.setAward(word);
		
		cout << "Year: ";
		getline(cin,word);
		tempAA.setYear(word);
		
		cout << "Winner? ";
		getline(cin,word);
		tempAA.setWinner(word);
		
		cout << "Film: ";
		getline(cin,word);
		tempAA.setFilm(word);
		
		cout << "Is this correct (Y or N)? " << endl;
		cout << tempAA << endl;
	}
}
//**********************************************************


//***************** PICTURE DATABASE FUNCTIONS *************
void sortByFilm(vector<Movie>& vec)
{
	sort(vec.begin(), vec.end());
}

//build database
void pictureDatabase(vector<Movie>& vec)
{
	Movie temp;
	ifstream f("pictures.csv");
	string line; //for get line
	int count = 0; //to read specific items from the line
	
	while(getline(f,line))
	{
		stringstream s(line); //put line into string stream
		string word; //to parse string stream
		while(getline(s,word,','))
		{
			if (count == 0)
			{
				temp.setName(word);
				count += 1;
				continue;
			}
			if (count == 1)
			{
				temp.setYear(word);
				count += 1;
				continue;
			}
			if (count == 2)
			{
				temp.setNominations(word);
				count += 1;
				continue;
			}
			if (count == 3)
			{
				temp.setRating(word);
				count += 1;
				continue;
			}
			if (count == 4)
			{
				temp.setDuration(word);
				count += 1;
				continue;
			}
			if (count == 5)
			{
				temp.setGenre1(word);
				count += 1;
				continue;
			}
			if (count == 6)
			{
				temp.setGenre2(word);
				count += 1;
				continue;
			}
			if (count == 7)
			{
				temp.setRelease(word);
				count += 1;
				continue;
			}
			if (count == 8)
			{
				temp.setMetacritic(word);
				count += 1;
				continue;
			}
			if (count == 9)
			{
				temp.setSynposis(word);
				vec.push_back(temp);
				count = 0;
				break;
			}
		}
	}
	sortByFilm(vec);
}

vector<Movie> searchByMovieName(vector<Movie> movieVec)
{
	string word;
	vector<Movie> temp;
	bool flag = true;
	cout << "Enter a movie name: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < movieVec.size(); i++)
	{
		if (wordMatch(movieVec[i].getName(), word) == true)
		{
			temp.push_back(movieVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<Movie> searchByMovieYear(vector<Movie> movieVec)
{
	string word;
	vector<Movie> temp;
	bool flag = true;
	cout << "Enter a year: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < movieVec.size(); i++)
	{
		if (wordMatch(movieVec[i].getYear(), word) == true)
		{
			temp.push_back(movieVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<Movie> searchByMovieGenre(vector<Movie> movieVec)
{
	string word;
	vector<Movie> temp;
	bool flag = true;
	cout << "Enter a genre: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < movieVec.size(); i++)
	{
		if (wordMatch(movieVec[i].getGenre1(), word) == true || wordMatch(movieVec[i].getGenre2(), word) == true)
		{
			temp.push_back(movieVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

void sortMovieChoice(vector<Movie>& movieVec)
{
	char choice;
	do
	{
		cout << "Which field would you like to sort by? " << endl
		<< "A: Year" << endl
		<< "B: Number of Nominations" << endl
		<< "C: Rating" << endl
		<< "D: Genre" << endl
		<< "> ";
		cin >> choice;
		
		switch(toupper(choice))
		{
			case 'A':
				//all sorts (other than original name sort) done by insertion
				for (int i = 1; i < movieVec.size(); i++)
				{
					Movie temp = movieVec[i];
					int j = i - 1;
					while (j >= 0 && temp.getYear() <= movieVec[j].getYear())
					{
						movieVec[j+1] = movieVec[j];
						j = j-1;
					}
					movieVec[j+1] = temp;
				}
				break;
			case 'B':
				for (int i = 1; i < movieVec.size(); i++)
				{
					Movie temp = movieVec[i];
					int j = i - 1;
					while (j >= 0 && temp.getNominations() <= movieVec[j].getNominations())
					{
						movieVec[j+1] = movieVec[j];
						j = j-1;
					}
					movieVec[j+1] = temp;
				}
				break;
			case 'C':
				for (int i = 1; i < movieVec.size(); i++)
				{
					Movie temp = movieVec[i];
					int j = i - 1;
					while (j >= 0 && temp.getRating() <= movieVec[j].getRating())
					{
						movieVec[j+1] = movieVec[j];
						j = j-1;
					}
					movieVec[j+1] = temp;
				}
				break;
			case 'D':
				for (int i = 1; i < movieVec.size(); i++)
				{
					Movie temp = movieVec[i];
					int j = i - 1;
					while (j >= 0 && temp.getGenre1() <= movieVec[j].getGenre1())
					{
						movieVec[j+1] = movieVec[j];
						j = j-1;
					}
					movieVec[j+1] = temp;
				}
				break;
			default:
				cout << "I'm not sure what to do with that. Please choose an item from the list." << endl;
		}
	}while(toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C' && toupper(choice) != 'D');
	cout << "Sorting finished! Returning to main menu." << endl;
}

void movieCompleteSearch(vector<Movie> movieVec)
{
	char choice;
	char again = 'Y';
	do
	{
		int flag = 0;
		vector<Movie> temp;
		cout << "What would you like to search by?" << endl
			 << "A: Name " << endl
			 << "B: Year " << endl
			 << "C: Genre " << endl
			 << "> ";
		
		cin >> choice;
		switch(toupper(choice))
		{
			case 'A':
				(flag == 0) ? temp = searchByMovieName(movieVec) : temp = searchByMovieName(temp);
				if (temp.size() == 1)
				{
					modifyM();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
			case 'B':
				(flag == 0) ? temp = searchByMovieYear(movieVec) : temp = searchByMovieYear(temp);
				if (temp.size() == 1)
				{
					modifyM();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
			case 'C':
				(flag == 0) ? temp = searchByMovieGenre(movieVec) : temp = searchByMovieGenre(temp);
				if (temp.size() == 1)
				{
					modifyM();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
		}
	}while(toupper(again) == 'Y');
}

void moviePartialSearch(vector<Movie> mVec)
{
	char choice;
	char again = 'Y';
	do
	{
		int flag = 0;
		vector<Movie> temp;
		cout << "What would you like to search by?" << endl
			 << "A: Name " << endl
			 << "B: Year " << endl
			 << "C: Genre " << endl
			 << "> ";
		
		cin >> choice;
		switch(toupper(choice))
		{
			case 'A':
				(flag == 0) ? temp = MpartialByName(mVec) : temp = MpartialByName(temp);
				if (temp.size() == 1)
				{
					modifyM();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
			case 'B':
				(flag == 0) ? temp = MpartialByYear(mVec) : temp = MpartialByYear(temp);
				if (temp.size() == 1)
				{
					modifyM();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
			case 'C':
				(flag == 0) ? temp = MpartialByGenre(mVec) : temp = MpartialByGenre(temp);
				if (temp.size() == 1)
				{
					modifyM();
				}
				cout << "Would you like to search again (Y or N)?";
				cin >> again;
				flag += 1;
				break;
		}
	}while(toupper(again) == 'Y');
}

vector<Movie> MpartialByName(vector<Movie> mVec)
{
	string word;
	vector<Movie> temp;
	bool flag = true;
	cout << "Enter your criteria: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < mVec.size(); i++)
	{
		if (partialMatch(word, mVec[i].getName()))
		{
			temp.push_back(mVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<Movie> MpartialByYear(vector<Movie> mVec)
{
	string word;
	vector<Movie> temp;
	bool flag = true;
	cout << "Enter your criteria: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < mVec.size(); i++)
	{
		if (partialMatch(word, mVec[i].getYear()))
		{
			temp.push_back(mVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

vector<Movie> MpartialByGenre(vector<Movie> mVec)
{
	string word;
	vector<Movie> temp;
	bool flag = true;
	cout << "Enter your criteria: " << endl;
	cin.ignore();
	getline(cin, word);
	
	for (int i = 0; i < mVec.size(); i++)
	{
		if (partialMatch(word, mVec[i].getGenre1()) || partialMatch(word, mVec[i].getGenre2()))
		{
			temp.push_back(mVec[i]);
			flag = false;
		}
	}
	if (flag == true)
		cout << word << " not found in the database." << endl;
	
	cout << word << " found " << temp.size() << " times." << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i];
	}
	return temp;
}

void modifyM()
{
	char modify;
	Movie tempM;
	string word;
	cout << "Would you like to modify this entry (Y or N)?" << endl
		 << "> ";
	cin >> modify;
	
	if (toupper(modify) == 'Y')
	{
		cout << "New Name: ";
		cin.ignore();
		getline(cin, word);
		tempM.setName(word);
		
		cout << "Year: ";
		getline(cin,word);
		tempM.setYear(word);
		
		cout << "Nominations: ";
		getline(cin,word);
		tempM.setNominations(word);
		
		cout << "Rating: ";
		getline(cin,word);
		tempM.setRating(word);
		
		cout << "Duration: ";
		getline(cin,word);
		tempM.setDuration(word);
		
		cout << "Genre 1: ";
		getline(cin,word);
		tempM.setGenre1(word);
		
		cout << "Genre 2: ";
		getline(cin,word);
		tempM.setGenre2(word);
		
		cout << "Release: ";
		getline(cin,word);
		tempM.setRelease(word);
		
		cout << "Metacritic: ";
		getline(cin,word);
		tempM.setMetacritic(word);
		
		cout << "Synopsis: ";
		getline(cin,word);
		tempM.setSynposis(word);
		
		cout << "Is this correct (Y or N)? " << endl;
		cout << tempM << endl;
	}
}
//*******************************************************

