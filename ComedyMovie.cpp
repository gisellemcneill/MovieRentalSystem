// ------------------------------------------------ ComedyMovie.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/27/26

// Date of Last Modification: 5/27/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the ComedyMovie class, which serves as the derived class of base class Movie
// in the movie rental store inventory system.

// Implements ComedyMovie member functions including:
// ComedyMovie(), display(), operator<(), operator==()
// ComedyComparator::operator()()

// Also implements ComedyComparator::operator()() used by std::set to maintain
// sorted order of ComedyMovie objects by title then release year.
// --------------------------------------------------------------------------------------------------------------------

#include "ComedyMovie.h"

// ------------------------------------ ComedyMovie Constructor ------------------------------------
// Description:
// Initializes a ComedyMovie object with the given title, director, release year, and stock.
// Genre is hardcoded to 'F' for funny.
//
// Preconditions:
// None
//
// Postconditions:
// ComedyMovie object is initialized and genre set to 'F'
// --------------------------------------------------------------------------------------------
ComedyMovie::ComedyMovie(string title, string director, int year, int stock)
    : Movie(title, director, year, 'F', stock) {}
// End of ComedyMovie()


// ------------------------------------ display() ------------------------------------
// Description:
// Prints the ComedyMovie attributes to the output stream in the format:
// genre, stock, director, title, year
//
// Preconditions:
// ComedyMovie object is initialized
//
// Postconditions:
// ComedyMovie information is printed to the output stream
// ComedyMovie object is unchanged
// --------------------------------------------------------------------------------------------
void ComedyMovie::display(ostream& out) const {

    out << genre << ", " << stock << ", " << director
        << ", " << title << ", " << releaseYear << endl;

}
// End of display()


// ------------------------------------ operator< ------------------------------------
// Description:
// Compares two ComedyMovie objects for sorting
// Sorts by title first, if titles are equal, it then compares releaseYear
// Uses static_cast since genre is already known to be 'F'
//
// Preconditions:
// Both Movie objects are ComedyMovie instances
//
// Postconditions:
// Returns true if this ComedyMovie comes before the other in sorted order
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool ComedyMovie::operator<(const Movie& other) const {

    const ComedyMovie& o = static_cast<const ComedyMovie&>(other);

    if (title != o.title) {
        return title < o.title;
    }

    return releaseYear < o.releaseYear;
}
// End of operator<()


// ------------------------------------ operator== ------------------------------------
// Description:
// Compares two ComedyMovie objects for equality.
// Two ComedyMovies are equal if they share the same title and release year.
// Uses static_cast since genre is already known to be 'F'
//
// Preconditions:
// Both Movie objects are ComedyMovie instances
//
// Postconditions:
// Returns true if both ComedyMovies are equal
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool ComedyMovie::operator==(const Movie& other) const {

    const ComedyMovie& o = static_cast<const ComedyMovie&>(other);

    return (title == o.title && releaseYear == o.releaseYear);
}
// End of operator==()


// ------------------------------------ ComedyComparator::operator() ------------------------------------
// Description:
// Comparator function used by std::set to maintain sorted order of ComedyMovie objects.
// Reuses comparison logic
//
// Preconditions:
// Both ComedyMovie pointers are valid and not nullptr
//
// Postconditions:
// Returns true if ComedyMovie a comes before ComedyMovie b in sorted order
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool ComedyComparator::operator()(const ComedyMovie* a, const ComedyMovie* b) const {

    return *a < *b;

}
// End of ComedyComparator::operator()()