// ------------------------------------------------ MovieFactory.cpp --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/04/26

// Date of Last Modification: 6/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// A factory class used to build the derived classes of the abstract Movie class at runtime. Allows for
// the derived Movie classes to be treated polymorphically and cast under the generic Movie type.

// --------------------------------------------------------------------------------------------------------------------

#include "MovieFactory.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"
#include <sstream>
#include <string>

// ------------------------------------ createMovie() ------------------------------------
// Description:
// Builds a Movie object of the correct genre determeined by the given genre char
// with the given attributes, by calling each genre of Movie copy constructor
// and casting it under the base Movie class for polymorphism
//
// Preconditions:
// streamstream& attributes is a valid stringstream object and not empty
//
// Postconditions:
// Returns a specific genre of derived Movie object under generic type Movie determined by genre
// --------------------------------------------------------------------------------------------
Movie* MovieFactory::createMovie(char genre, int stock, const string& director, const string& title, stringstream& attributes) {
    switch (genre) {
        //case for genre 'F' comedy; returns ComedyMovie
        case 'F' : {
            int year;
            attributes >> year;
            return new ComedyMovie(title, director, year, stock);
        }

        //case for genre 'D' drama; returns DramaMovie
        case 'D' : {
            int year;
            attributes >> year;
            return new DramaMovie(title, director, year, stock);
        }

        //case for genre 'C' classic; returns ClassicMovie
        case 'C' : {
            string fName, lName;
            int month, year;
            
            attributes >> fName >> lName >> month >> year;
            string actor = fName + " " + lName;
            return new ClassicMovie(title, director, month, year, stock, actor);
        }

        default :
            return nullptr;

    }
}