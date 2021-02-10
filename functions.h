//
//  functions.h
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
#include "actorActress.h"
#include "movie.h"
#include <algorithm>

using namespace std;

#ifndef functions_h
#define functions_h

//build database functions
void actorActressDatabase(vector<ActorActress>& vec);
void pictureDatabase(vector<Movie>& vec);
//***************************************

//sort functions
void sortByName(vector<ActorActress>& vec);
void sortByFilm(vector<Movie>& vec);
void sortByUserChoice(vector<ActorActress>& aaVec, vector<Movie>& movieVec);
void sortAAChoice(vector<ActorActress>& aavec);
void sortMovieChoice(vector<Movie>& movieVec);
//**********************************

//random functions
char mainMenu();
void addRecord(vector<ActorActress>& aaVec, vector<Movie>& movieVec);
bool wordMatch(string w1, string w2);
void writeToCSV(vector<ActorActress>& aaVec, vector<Movie>& movieVec);

//search functions
void searchDatabase(vector<ActorActress>& aaVec, vector<Movie>& movieVec);

//actor actress database
vector<ActorActress> searchByName(vector<ActorActress> aaVec);
vector<ActorActress> searchByAward(vector<ActorActress> aaVec);
vector<ActorActress> searchByYear(vector<ActorActress> aaVec);
vector<ActorActress> searchByFilm(vector<ActorActress> aaVec);
void actorActressCompleteSearch(vector<ActorActress> aaVec);
void actorActressPartialSearch(vector<ActorActress> aaVec);
vector<ActorActress> AApartialByName(vector<ActorActress> aaVec);
vector<ActorActress> AApartialByAward(vector<ActorActress> aaVec);
vector<ActorActress> AApartialByYear(vector<ActorActress> aaVec);
vector<ActorActress> AApartialByFilm(vector<ActorActress> aaVec);
void modifyAA();

//picture database
vector<Movie> searchByMovieName(vector<Movie> mVec);
vector<Movie> searchByMovieYear(vector<Movie> mVec);
vector<Movie> searchByMovieGenre(vector<Movie> mVec);
void movieCompleteSearch(vector<Movie> mVec);
void moviePartialSearch(vector<Movie> mVec);
vector<Movie> MpartialByName(vector<Movie> mVec);
vector<Movie> MpartialByYear(vector<Movie> mVec);
vector<Movie> MpartialByGenre(vector<Movie> mVec);
void modifyM();

//***************************************************************************
#endif /* functions_h */
