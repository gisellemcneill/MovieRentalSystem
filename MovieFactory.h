// ------------------------------------------------ MovieFactory.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/04/26

// Date of Last Modification: 6/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// A factory class used to build the derived classes of the abstract Movie class at runtime. Allows for
// the derived Movie classes to be treated polymorphically and cast under the generic Movie type.

// --------------------------------------------------------------------------------------------------------------------


#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "Movie.h"

using namespace std;

class MovieFactory {
public:
	//movie builder
	Movie* createMovie(char genre, int stock, const string& director, const string& title, stringstream& attributes);
};
#endif
