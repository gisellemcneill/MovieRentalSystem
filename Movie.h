// ------------------------------------------------ Movie.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/27/26

// Date of Last Modification: 5/27/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the Movie class, which serves as the abstract base class for all movie types in the
// movie rental store inventory system. Movie inherits from Media and provides shared attributes
// and behavior for all movie genres, including title, director, release year, genre, type, and stock.

// Each derived class (ComedyMovie, DramaMovie, ClassicMovie) must implement the pure virtual
// functions display(), operator<, and operator== to define genre-specific display formatting,
// sorting behavior, and equality comparison.

// The class uses a virtual destructor to ensure proper memory cleanup when deleting derived
// class objects through a base class pointer. Stock management is handled at this level through
// incrementStock() and decrementStock(), which are shared across all movie genres.

// --------------------------------------------------------------------------------------------------------------------


#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

class Movie {
public:
    //Constructor
    Movie(string title, string director, int year, char genre, int stock);
    virtual ~Movie(); //virtual destructor

    //getters
    string getTitle() const;
    string getDirector() const;
    int getYear() const;
    char getGenre() const;
    char getType() const;
    int getStock() const;

    //stock management
    void incrementStock(); //increase the stock
    bool decrementStock(); //decrease the stock

    //pure virtual functions
    virtual void display(ostream& out) const = 0; //Used to display Movie
    virtual bool operator<(const Movie& other) const = 0; //To compare two Movie objects
    virtual bool operator==(const Movie& other) const = 0; //To check equality among two Movie objects

    //To be used with display
    friend ostream& operator<<(ostream& out, const Movie& movie); //Works with display to print

protected:
    string title;
    string director;
    int releaseYear;
    char genre;
    char type;
    int stock;

};
#endif