//
//  movie.cpp
//  Data_Structures_Final_Project
//
//  Created by Eric Tyson on 11/27/20.
//

#include "movie.h"

using namespace std;

Movie::Movie()
{
	name = "name";
	year = "0";
	nomination = "0";
	rating = "0.0";
	duration = "0";
	genre1 = "genre 1";
	genre2 = "genre 2";
	release = "release";
	metacritic = "0";
	synopsis = "synopsis";
}

//cout overload
ostream& operator<<(ostream& out, const Movie& m1)
{
	out << "Film: " << m1.name << endl << "Year: " << m1.year << endl << "Nomination: " << m1.nomination << endl << "Rating: " << m1.rating << endl << "Duration: " << m1.duration << endl << "Genre 1: " << m1.genre1 << endl << "Genre 2: " << m1.genre2 << endl << "Release: " << m1.release << endl << "Metacritic: " << m1.metacritic << endl << "Synopsis: " << m1.synopsis << endl;
	return out;
}

// less than function to sort by name
bool Movie::operator< (const Movie& m1) const
{
	return name < m1.name;
}
