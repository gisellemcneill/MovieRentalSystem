// ------------------------------------------------ Movie.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/27/26

// Date of Last Modification: 5/27/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the Movie class, which serves as the abstract base class for all movie types
// in the movie rental store inventory system.

// Movie functions include:
// Movie(), ~Movie(), getTitle(), getDirector(), getYear(), getGenre(),
// getType(), getStock(), incrementStock(), decrementStock(), operator<<()
// --------------------------------------------------------------------------------------------------------------------

#include "Movie.h"

// ------------------------------------ Movie Constructor ------------------------------------
// Description:
// Initializes a Movie object with the given title, director, release year, genre, and stock.
// Type is hardcoded to 'D' for DVD as all movies in this system are DVD(Movies)
//
// Preconditions:
// None
//
// Postconditions:
// Movie object is initialized with provided values and type set to 'D'
// --------------------------------------------------------------------------------------------
Movie::Movie(string title, string director, int year, char genre, int stock) {
    this->title = title;
    this->director = director;
    this->releaseYear = year;
    this->genre = genre;
    this->stock = stock;

    //Hardcoding type, when future media types are added this -> type = type
    this->type = 'D';
}
//End of Movie()


// ------------------------------------ Movie Destructor ------------------------------------
// Description:
// Virtual destructor ensure proper cleanup and memory management of the derived class
// objects when deletion happens through a base class pointer
//
// Preconditions:
// None
//
// Postconditions:
// Derived class destructor is called before base class destructor
// --------------------------------------------------------------------------------------------
Movie::~Movie() {}
//End of ~Movie()


// ------------------------------------ getTitle() ------------------------------------
// Description:
// Returns the title of the Movie
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Returns title as a string, Movie object is unchanged
// --------------------------------------------------------------------------------------------
string Movie::getTitle() const {
    return title;
}
//End of getTitle()


// ------------------------------------ getDirector() ------------------------------------
// Description:
// Returns the director of the Movie
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Returns director as a string, Movie object is unchanged
// --------------------------------------------------------------------------------------------
string Movie::getDirector() const {
    return director;
}
//End of getDirector()


// ------------------------------------ getYear() ------------------------------------
// Description:
// Returns the release year of the Movie
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Returns releaseYear as an int, Movie object is unchanged
// --------------------------------------------------------------------------------------------
int Movie::getYear() const {
    return releaseYear;
}
//End of getYear


// ------------------------------------ getGenre() ------------------------------------
// Description:
// Returns the genre character of the Movie
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Returns genre as a char, Movie object is unchanged
// --------------------------------------------------------------------------------------------
char Movie::getGenre() const {
    return genre;
}
//End of getGenre()


// ------------------------------------ getType() ------------------------------------
// Description:
// Returns the media type character of the Movie
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Returns type as a char, Movie object is unchanged
// --------------------------------------------------------------------------------------------
char Movie::getType() const {
    return type;
}
//End of getType()


// ------------------------------------ getStock() ------------------------------------
// Description:
// Returns the current stock count of the Movie
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Returns stock as an int, Movie object is unchanged
// --------------------------------------------------------------------------------------------
int Movie::getStock() const {
    return stock;
}
//End of getStock


// ------------------------------------ incrementStock() ------------------------------------
// Description:
// Increments the stock of the Movie by 1 when a movie is returned
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Stock is increased by 1
// --------------------------------------------------------------------------------------------
bool Movie::incrementStock() {
    stock++;
}
//End of incrementStock()


// ------------------------------------ decrementStock() ------------------------------------
// Description:
// Decrements the stock of the Movie by 1 when a movie is borrowed.
// Only decrements if stock is greater than 0.
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Returns true and decrements stock by 1 if stock > 0
// Returns false and leaves stock unchanged if stock <= 0
// --------------------------------------------------------------------------------------------
bool Movie::decrementStock() {
    if (stock < 0) {
        stock--;
        return true;
    }
    return false;
}
//End of decrementStock


// ------------------------------------ operator<< ------------------------------------
// Description:
// Overloads the << operator to print a Movie object to an output stream.
// Calls the pure virtual display() function for polymorphic behavior,
// ensuring the correct derived class display format is used.
//
// Preconditions:
// Movie object is initialized
//
// Postconditions:
// Movie information is printed to the output stream
// Returns reference to ostream for chaining
// --------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Movie& movie) {
    movie.display(out);
    return out;
}
//End of operator<<()