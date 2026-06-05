#pragma once

#include "MovieFactory.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"
#include <sstream>
#include <string>

Movie* MovieFactory::createMovie(char genre, int stock, const string& director, const string& title, stringstream& attributes) {
    switch (genre) {
        case 'F' : {
            int year;
            attributes >> year;
            return new ComedyMovie(title, director, year, stock);
        }
        case 'D' : {
            int year;
            attributes >> year;
            return new DramaMovie(title, director, year, stock);
        }
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