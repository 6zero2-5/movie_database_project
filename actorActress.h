//
//  actorActress.h
//  Data_Structures_Final_Project
//
//  Created by Eric Tyson on 11/27/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

#ifndef actorActress_h
#define actorActress_h

class ActorActress
{
private:
	string year; //searchable
	string award; //searchable
	string winner; //don't search
	string name; //searchable
	string film; //searchable
public:
	ActorActress();
	void setYear(string _year) { year = _year; }
	string getYear() { return year; }
	void setAward(string _award) { award = _award; }
	string getAward() { return award; }
	void setWinner(string _winner) { winner = _winner; }
	string getWinner() { return winner; }
	void setName(string _name) { name = _name; }
	string getName() { return name; }
	void setFilm(string _film) { film = _film; }
	string getFilm() { return film; }
	//overload cout
	friend ostream& operator<<(ostream& out, const ActorActress& aa);
	bool operator< (const ActorActress& aa) const;
};
#endif /* actorActress_h */
