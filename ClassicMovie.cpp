// ------------------------------------------------ ComedyMovie.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/29/26

// Date of Last Modification: 5/29/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the ClassicMovie class, which serves as the derived class of base class Movie
// in the movie rental store inventory system.

// Implements ClassicMovie member functions including:
// ClassicMovie(), display(), operator<(), operator==()
// ClassicComparator::operator()()

// Also implements ClassicComparator::operator()() used by std::set to maintain
// sorted order of ClassicMovie objects by release date then major actor.
// --------------------------------------------------------------------------------------------------------------------

#include "ClassicMovie.h"

// ------------------------------------ ClassicMovie Constructor ------------------------------------
// Description:
// Initializes a ClassicMovie object with the given title, director, major actor, release month, release year, and stock.
// Genre is hardcoded to 'C' for classic.
//
// Preconditions:
// None
//
// Postconditions:
// ClassicMovie object is initialized and genre set to 'C'
// --------------------------------------------------------------------------------------------
ClassicMovie::ClassicMovie(string title, string director, string actor, int month, int year, int stock)
    : Movie(title, director, year, 'C', stock) {
    releaseMonth = month;
    majorActor = actor;
}
// End of ClassicMovie()


// ------------------------------------ display() ------------------------------------
// Description:
// Prints the ClassicMovie attributes to the output stream in the format:
// genre, stock, director, title, year
//
// Preconditions:
// ClassicMovie object is initialized
//
// Postconditions:
// ClassicMovie information is printed to the output stream
// ClassicMovie object is unchanged
// --------------------------------------------------------------------------------------------
void ClassicMovie::display(ostream& out) const {

    out << genre << ", " << stock << ", " << releaseMonth
        << " " << releaseYear << ", " << majorActor << endl;

}
// End of display()


// ------------------------------------ operator< ------------------------------------
// Description:
// Compares two ClassicMovie objects for sorting
// Sorts by releaseYear first, if years are equal, then compares by releaseMonth, if months are equal, then compares majorActor
// Uses static_cast since genre is already known to be 'C'
//
// Preconditions:
// Both Movie objects are ClassicMovie instances
//
// Postconditions:
// Returns true if this ClassicMovie comes before the other in sorted order
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool ClassicMovie::operator<(const Movie& other) const {

    const ClassicMovie& o = static_cast<const ClassicMovie&>(other);

    if (releaseYear != o.releaseYear) {
        return releaseYear < o.releaseYear;
    }

    if (releaseMonth != o.releaseMonth) {
        return releaseMonth < o.releaseMonth;
    }

    return majorActor < o.majorActor;
}
// End of operator<()


// ------------------------------------ operator== ------------------------------------
// Description:
// Compares two ClassicMovie objects for equality.
// Two ClassicMovies are equal if they share the same release date and major actor.
// Uses static_cast since genre is already known to be 'C'
//
// Preconditions:
// Both Movie objects are ClassicMovie instances
//
// Postconditions:
// Returns true if both ClassicMovies are equal
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool ClassicMovie::operator==(const Movie& other) const {

    const ClassicMovie& o = static_cast<const ClassicMovie&>(other);

    return (releaseYear == o.releaseYear && releaseMonth == o.releaseMonth && majorActor == o.majorActor);
}
// End of operator==()


// ------------------------------------ ClassicComparator::operator() ------------------------------------
// Description:
// Comparator function used by std::set to maintain sorted order of ClassicMovie objects.
// Reuses comparison logic
//
// Preconditions:
// Both ClassicMovie pointers are valid and not nullptr
//
// Postconditions:
// Returns true if ClassicMovie a comes before ClassicMovie b in sorted order
// Both objects are unchanged
// --------------------------------------------------------------------------------------------
bool ClassicComparator::operator()(const ClassicMovie* a, const ClassicMovie* b) const {

    return *a < *b;

}
// End of ClassicComparator::operator()()