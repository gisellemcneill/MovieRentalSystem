// ------------------------------------------------ ComedyMovie.h -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/27/26

// Date of Last Modification: 5/27/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the ComedyMovie class, which represents a comedy genre movie in the
// movie rental store inventory system. ComedyMovie inherits from Movie and implements
// the pure virtual functions declared in the Movie base class.

// ComedyMovie objects are sorted and identified by title, then release year.
// The genre is hardcoded as 'F' for funny

// The ComedyComparator struct is defined here and is used by std::set to maintain
// sorted order of ComedyMovie objects automatically upon insertion.
// --------------------------------------------------------------------------------------------------------------------
#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "Movie.h"

class ComedyMovie : public Movie {
    public:

    //constructor
    ComedyMovie(string title, string director, int year, int stock);

    void display(ostream& out) const override;
    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;
};

// ------------------------------------ ComedyComparator ------------------------------------
// Description:
// Comparator struct used by std::set to sort ComedyMovie objects.
// Sorts by title first, then by release year if titles are equal.
// --------------------------------------------------------------------------------------------
struct ComedyComparator {
    bool operator()(const ComedyMovie* a, const ComedyMovie* b) const;
};
#endif