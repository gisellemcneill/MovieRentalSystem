// ------------------------------------------------ DramaMovie.h -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/29/26

// Date of Last Modification: 5/29/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the DramaMovie class, which represents a drama genre movie in the
// movie rental store inventory system. DramaMovie inherits from Movie and implements
// the pure virtual functions declared in the Movie base class.

// DramaMovie objects are sorted and identified by director, then title.
// The genre is hardcoded as 'D' for drama

// The DramaComparator struct is defined here and is used by std::set to maintain
// sorted order of DramaMovie objects automatically upon insertion.
// --------------------------------------------------------------------------------------------------------------------
#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "Movie.h"

class DramaMovie : public Movie {
    public:

    //constructor
    DramaMovie(string title, string director, int year, int stock);

    void display(ostream& out) const override;
    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;
};

// ------------------------------------ DramaComparator ------------------------------------
// Description:
// Comparator struct used by std::set to sort DramaMovie objects.
// Sorts by director first, then by title if directors are equal.
// --------------------------------------------------------------------------------------------
struct DramaComparator {
    bool operator()(const DramaMovie* a, const DramaMovie* b) const;
};
#endif