// ------------------------------------------------ MovieList.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/1/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the MovieList class, which serves as the storage and retrieval system
// for all movies in the inventory system.

// Implements MovieList member functions including:
// MovieList(), ~MovieList(), add(), findComedy(), findDrama(), findClassic(), display()

// MovieList maintains three sorted sets, one per genre, each with a custom comparator.
// Memory ownership: MovieList is responsible for deleting all Movie objects
// stored in its sets
// --------------------------------------------------------------------------------------------------------------------

#include "MovieList.h"
#include <iostream>

// ------------------------------------ MovieList Constructor ------------------------------------
// Description:
// Initializes an empty MovieList with three empty sorted sets,
// one for each genre. Sets are automatically initialized by their
// default constructors.
//
// Preconditions:
// None
//
// Postconditions:
// MovieList is initialized with three empty sets ready to receive movies
// --------------------------------------------------------------------------------------------
MovieList::MovieList() {}
//End of MovieList()


// ------------------------------------ MovieList Destructor ------------------------------------
// Description:
// Deletes all dynamically allocated Movie objects stored in all three
// genre sets to prevent memory leaks.
//
// Preconditions:
// None
//
// Postconditions:
// All Movie objects in all three sets are deleted
// All three sets are empty
// --------------------------------------------------------------------------------------------
MovieList::~MovieList() {

    for (ComedyMovie* m: comedies) delete m;

    for (DramaMovie* m: dramas) delete m;

    for (ClassicMovie* m: classics) delete m;

}
//End of ~MovieList()


// ------------------------------------ add() ------------------------------------------------
// Description:
// Adds a Movie object to the correct genre set based on the movie's genre char.
// Uses static_cast to safely cast Movie* to the correct subclass pointer since
// genre is already known at this point.
//
// Preconditions:
// movie pointer is valid and not nullptr
//
// Postconditions:
// Movie is inserted into the correct genre set, maintaining sorted order
// If the genre is invalid, the movie is discarded, and an error message is printed
// --------------------------------------------------------------------------------------------
void MovieList::add(Movie* movie) {

    switch (movie -> getGenre()) {
        case 'F':
            comedies.insert(static_cast<ComedyMovie*>(movie));
            break;
        case 'D':
            dramas.insert(static_cast<DramaMovie*>(movie));
        case'C'
            classics.insert(static_cast<ClassicMovie*>(movie));
        default:
            cout << "ERROR: Genre " << movie -> getGenre() << " not recognized."
                << "\nMovie was disregarded." << endl;
            break;
    }
}
//End of add()


// ------------------------------------ findComedy() ------------------------------------
// Description:
// Searches the comedies set for a ComedyMovie matching the given title and year.
// ComedyMovies are sorted by title, then release year
//
// Preconditions:
// title is a valid string, year is a valid integer
//
// Postconditions:
// Returns pointer to matching ComedyMovie if found, Returns nullptr if no match is found
// comedies set is unchanged
// --------------------------------------------------------------------------------------------
ComedyMovie* MovieList::findComedy(const string &title, int year) const {

    for (ComedyMovie* m: comedies) {
        if (m -> getTitle() == title && m -> getYear() == year) {
            return m;
        }
    }
    return nullptr;
}
//End of findComedy()



// ------------------------------------ findDrama() ------------------------------------------
// Description:
// Searches the comedies set for a DramaMovie matching the given director and title.
// DramaMovies are sorted by director, then title
//
// Preconditions:
// director is a valid string, title is a valid string
//
// Postconditions:
// Returns pointer to matching DramaMovie if found, Returns nullptr if no match is found
// dramas set is unchanged
// --------------------------------------------------------------------------------------------
DramaMovie* MovieList::findDrama(const string &director, const string &title) const {

    for (DramaMovie* m: dramas) {
        if (m -> getDirector() == director && m -> getTitle() == title) {
            return m;
        }
    }
    return nullptr;
}
//End of findDrama()


// ------------------------------------ findClassic() ------------------------------------------
// Description:
// Searches the classics set for a ClassicMovie matching the given releaseMonth, year
// and majorActor. ClassicMovies are sorted by releaseMonth and year along with majorActor
//
// Preconditions:
// releaseMonth and year are valid integers, majorActor is a valid string
//
// Postconditions:
// Returns pointer to matching ClassicMovie if found, Returns nullptr if no match is found
// classics set is unchanged
// --------------------------------------------------------------------------------------------
ClassicMovie* MovieList::findClassic(int month, int year, const string &actor) const {

    for (ClassicMovie* m: classics) {
        if (m -> getReleaseMonth() == month && m -> getYear() == year
            && m -> getMajorActor() == actor) {
            return m;
        }
    }
    return nullptr;
}
//End of findClassic()


// ------------------------------------ display() ------------------------------------
// Description:
// Displays all movies in sorted order by genre.
// Prints Comedy movies first, Drama movies second, Classic movies third.
// Within each genre, movies are printed in their comparator-defined sorted order.
//
// Preconditions:
// None
//
// Postconditions:
// All movies printed sorted order by genre
// MovieList is unchanged
// --------------------------------------------------------------------------------------------