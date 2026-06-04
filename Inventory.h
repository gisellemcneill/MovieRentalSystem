// ------------------------------------------------ Inventory.h -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/1/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the Inventory class, which serves as the upper-most level of the
// inventory system. Inventory owns a MovieList and allows the Company class
// to add, find, and display all movies in the store.

// Inventory delegates all storage and retrieval logic to MovieList, keeping

// If future media types are added, Inventory can be extended to hold
// additional lists without changing the Company class interface.
// --------------------------------------------------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include "MovieList.h"

using namespace std;

class Inventory {

public:
    // constructor
    Inventory();

    // destructor
    ~Inventory();

    // adds a Movie to the correct genre set via MovieList
    void addMovie(Movie* movie);

    //genre-specific find functions — delegate to MovieList
    ComedyMovie* findComedy(const string& title, int year) const;
    DramaMovie* findDrama(const string& director, const string& title) const;
    ClassicMovie* findClassic(int month, int year, const string& actor) const;

    // displays all movies in sorted order via MovieList
    void displayInventory() const;

private:
    MovieList movieList;  // owns all movies in the inventory
};

#endif