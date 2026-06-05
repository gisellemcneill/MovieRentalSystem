// ------------------------------------------------ ClassicMovie.h -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/29/26

// Date of Last Modification: 06/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the ClassicMovie class, which represents a classic genre movie in the
// movie rental store inventory system. ClassicMovie inherits from Movie and implements
// the pure virtual functions declared in the Movie base class.

// ClassicMovie objects are sorted and identified by release year, release month, then majorActor
// The genre is hardcoded as 'C' for classic

// The ClassicComparator struct is defined here and is used by std::set to maintain
// sorted order of ClassicMovie objects automatically upon insertion.
// --------------------------------------------------------------------------------------------------------------------
#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H

#include "Movie.h"
using namespace std;

class ClassicMovie : public Movie {

    public:

    //constructor
    ClassicMovie(const string& title, const string& director, int month, int year,
        int stock, const string& actor);
    ClassicMovie(const ClassicMovie& other);

    Movie* clone() override;

    string getMajorActor() const;
    int getReleaseMonth() const;

    bool sameClassicMovie(const ClassicMovie& other) const;

    void display(ostream& out) const override;
    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;

    private:

    string majorActor;
    int releaseMonth;
};

// ------------------------------------ ClassicComparator ------------------------------------
// Description:
// Comparator struct used by std::set to sort ClassicMovie objects.
// Sorts by release year, release month, then majorActor
// --------------------------------------------------------------------------------------------
struct ClassicComparator {
    bool operator()(const ClassicMovie* a, const ClassicMovie* b) const;
};
#endif