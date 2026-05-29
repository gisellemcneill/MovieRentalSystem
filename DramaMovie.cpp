// ------------------------------------------------ ComedyMovie.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/29/26

// Date of Last Modification: 5/29/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the DramaMovie class, which serves as the derived class of base class Movie
// in the movie rental store inventory system.

// Implements DramaMovie member functions including:
// DramaMovie(), display(), operator<(), operator==()
// DramaComparator::operator()()

// Also implements DramaComparator::operator()() used by std::set to maintain
// sorted order of DramaMovie objects by director then title.
// --------------------------------------------------------------------------------------------------------------------

#include "DramaMovie.h"

// ------------------------------------ DramaMovie Constructor ------------------------------------
// Description:
// Initializes a DramaMovie object with the given title, director, release year, and stock.
// Genre is hardcoded to 'D' for drama.
//
// Preconditions:
// None
//
// Postconditions:
// DramaMovie object is initialized and genre set to 'D'
// --------------------------------------------------------------------------------------------
DramaMovie::DramaMovie(string title, string director, int year, int stock)
    : Movie(title, director, year, 'D', stock) {}
// End of DramaMovie()


// ------------------------------------ display() ------------------------------------
// Description:
// Prints the DramaMovie attributes to the output stream in the format:
// genre, stock, director, title, year
//
// Preconditions:
// DramaMovie object is initialized
//
// Postconditions:
// DramaMovie information is printed to the output stream
// DramaMovie object is unchanged
// --------------------------------------------------------------------------------------------
void DramaMovie::display(ostream& out) const {

    out << genre << ", " << stock << ", " << director
        << ", " << title << endl;

}
// End of display()


// ------------------------------------ operator< ------------------------------------
// Description:
// Compares two DramaMovie objects for sorting
// Sorts by title first, if titles are equal, it then compares releaseYear
// Uses static_cast since genre is already known to be 'D'
//
// Preconditions:
// Both Movie objects are DramaMovie instances
//
// Postconditions:
// Returns true if this DramaMovie comes before the other in sorted order
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool DramaMovie::operator<(const Movie& other) const {

    const DramaMovie& o = static_cast<const DramaMovie&>(other);

    if (director != o.director) {
        return director < o.director;
    }

    return title < o.title;
}
// End of operator<()


// ------------------------------------ operator== ------------------------------------
// Description:
// Compares two DramaMovie objects for equality.
// Two DramaMovies are equal if they share the same director and title.
// Uses static_cast since genre is already known to be 'D'
//
// Preconditions:
// Both Movie objects are DramaMovie instances
//
// Postconditions:
// Returns true if both DramaMovies are equal
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool DramaMovie::operator==(const Movie& other) const {

    const DramaMovie& o = static_cast<const DramaMovie&>(other);

    return (director == o.director && title == o.title);
}
// End of operator==()


// ------------------------------------ DramaComparator::operator() ------------------------------------
// Description:
// Comparator function used by std::set to maintain sorted order of DramaMovie objects.
// Reuses comparison logic
//
// Preconditions:
// Both DramaMovie pointers are valid and not nullptr
//
// Postconditions:
// Returns true if DramaMovie a comes before DramaMovie b in sorted order
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool DramaComparator::operator()(const DramaMovie* a, const DramaMovie* b) const {

    return *a < *b;

}
// End of DramaComparator::operator()()