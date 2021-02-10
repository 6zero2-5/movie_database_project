//
//  actorActress.cpp
//  Data_Structures_Final_Project
//
//  Created by Eric Tyson on 11/27/20.
//

#include "actorActress.h"

using namespace std;

//default constructor
ActorActress::ActorActress()
{
	year = "0";
	award = "Award";
	winner = "0";
	name = "Name";
	film = "Film";
}

//cout overload
ostream& operator<<(ostream& out, const ActorActress& aa)
{
	out << "Film: " << aa.film << endl << "Year: " << aa.year << endl << "Award: " << aa.award << endl << "Actor/Actress: " << aa.name << endl << "Win? " << aa.winner << endl;
	return out;
}

// less than function to sort by name
bool ActorActress::operator< (const ActorActress& aa) const
{
	return name < aa.name;
}
