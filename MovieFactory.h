#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "Movie.h"

using namespace std;

class MovieFactory {
public:
	Movie* createMovie(char genre, int stock,const string& director, const string& title, stringstream& attributes);
};

#endif
