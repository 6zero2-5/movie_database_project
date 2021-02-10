//
//  movie.h
//  Data_Structures_Final_Project
//
//  Created by Eric Tyson on 11/27/20.
//

#include "actorActress.h"

using namespace std;

#ifndef movie_h
#define movie_h

class Movie
{
private:
	string name; //searchable & sortable
	string year; //searchablee & sortable
	string nomination; //doesn't make sense to search by
	string rating; //doesn't make sense to search by
	string duration; //doesn't make sense to search by
	string genre1; //do a single genre search function
	string genre2;
	string release; //don't search by this
	string metacritic; //don't saerch by this
	string synopsis; //don't search by this
public:
	Movie();
	void setName(string _name) { name = _name; }
	string getName() { return name; }
	void setYear(string _year) { year = _year; }
	string getYear() { return year; }
	void setNominations(string _nominations) { nomination = _nominations; }
	string getNominations() { return nomination; }
	void setRating(string _rating) { rating = _rating; }
	string getRating() { return rating; }
	void setDuration(string _duration) { duration = _duration; }
	string getDuration() { return duration; }
	void setGenre1(string _genre1) { genre1 = _genre1; }
	string getGenre1() { return genre1; }
	void setGenre2(string _genre2) { genre2 = _genre2; }
	string getGenre2() { return genre2; }
	void setRelease(string _release) { release = _release; }
	string getRelease() { return release; }
	void setMetacritic(string _metacritic) { metacritic = _metacritic; }
	string getMetacritic() { return metacritic; }
	void setSynposis(string _synopsis) { synopsis = _synopsis; }
	string getSynopsis() { return synopsis; }
	friend ostream& operator<<(ostream& out, const Movie& m1);
	bool operator< (const Movie& m1) const;
};

#endif /* movie_h */
