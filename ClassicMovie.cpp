// ------------------------------------------------ ClassicMovie.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/29/26

// Date of Last Modification: 6/05/26

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
ClassicMovie::ClassicMovie(const string& title, const string& director, int month, int year,
        int stock, const string& actor)
    : Movie(title, director, year, 'C', stock) {
    releaseMonth = month;
    majorActor = actor;
}
// End of ClassicMovie()


ClassicMovie::ClassicMovie(const ClassicMovie& other) 
    : Movie(other.title, other.director, other.releaseYear, 'C', other.stock) {
    releaseMonth = other.releaseMonth;
    majorActor = other.majorActor;
}

Movie* ClassicMovie::clone() {
    return new ClassicMovie(*this);
}

// ------------------------------------ getMajorActor() ------------------------------------
// Description:
// Returns the majorActor of the ClassicMovie
//
// Preconditions:
// ClassicMovie object is initialized
//
// Postconditions:
// Returns majorActor as a string, ClassicMovie object is unchanged
// --------------------------------------------------------------------------------------------
string ClassicMovie::getMajorActor() const {
    return majorActor;
}
//End of getMajorActor()



// ------------------------------------ getReleaseMonth() ------------------------------------
// Description:
// Returns the releaseMonth of the ClassicMovie
//
// Preconditions:
// ClassicMovie object is initialized
//
// Postconditions:
// Returns releaseMonth as an int, C;assocMovie object is unchanged
// --------------------------------------------------------------------------------------------
int ClassicMovie::getReleaseMonth() const {
    return releaseMonth;
}
//End of getReleaseMonth()


// ------------------------------------ sameClassicMovie() ------------------------------------
// Description:
// Checks whether two ClassicMovie objects represent the same movie identity.
// Movie identity is defined by title, director, release month, and release year.
// Note: majorActor is NOT included because multiple actors can exist for the same movie.
//
// Preconditions:
// Both ClassicMovie objects are valid and initialized.
//
// Postconditions:
// Returns true if both movies represent the same underlying movie (ignoring actor).
// Does NOT modify either object.
// --------------------------------------------------------------------------------------
bool ClassicMovie::sameClassicMovie(const ClassicMovie& other) const {
    return title == other.title &&
           director == other.director &&
           releaseYear == other.releaseYear &&
           releaseMonth == other.releaseMonth;
}
//End of sameClassicMovie()


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

    out << genre << " " << type << " " << title << " "
        << director << " " <<  releaseMonth << " " << releaseYear << " " << stock;

}
// End of display()


// ------------------------------------ operator< ------------------------------------
// Description:
// Compares two ClassicMovie objects for sorting
// Sorts by releaseYear first, if years are equal, then compares by releaseMonth,
// if months are equal, then compare majorActor
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