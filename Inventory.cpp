// ------------------------------------------------ Inventory.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the Inventory class, which serves as the upper-most level of the
// inventory system. All methods delegate directly to MovieList which handles
// all storage, retrieval, and display logic.

// Implements Inventory member functions including:
// Inventory(), ~Inventory(), addMovie(), findComedy(),
// findDrama(), findClassic(), findClassicsByTitle(), displayInventory()
// --------------------------------------------------------------------------------------------------------------------

#include "Inventory.h"

// ------------------------------------ Inventory Constructor ------------------------------------
// Description:
// Initializes an empty Inventory.
//
// Preconditions:
// None
//
// Postconditions:
// Inventory is initialized with an empty MovieList
// --------------------------------------------------------------------------------------------
Inventory::Inventory() {}
// End of Inventory()


// ------------------------------------ Inventory Destructor ------------------------------------
// Description:
// Destroys the Inventory object. MovieList destructor is automatically
// called and handles deletion of all stored Movie objects.
//
// Preconditions:
// None
//
// Postconditions:
// All Movie objects are deleted via the MovieList destructor
// --------------------------------------------------------------------------------------------
Inventory::~Inventory() {}
// End of ~Inventory()


// ------------------------------------ addMovie() ------------------------------------
// Description:
// Adds a Movie object to the correct genre set via MovieList.
// Delegates entirely to MovieList::add().
//
// Preconditions:
// movie pointer is valid and not nullptr
//
// Postconditions:
// Movie is inserted into correct genre set and maintains sorted order
// --------------------------------------------------------------------------------------------
void Inventory::addMovie(Movie* movie) {
    movieList.add(movie);
}
// End of addMovie()


// ------------------------------------ findComedy() ------------------------------------
// Description:
// Searches for a ComedyMovie matching the given title and year.
// Delegates entirely to MovieList::findComedy().
//
// Preconditions:
// title is a valid string, year is a valid integer
//
// Postconditions:
// Returns pointer to matching ComedyMovie if found
// Returns nullptr if no match found
// Inventory is unchanged
// --------------------------------------------------------------------------------------------
ComedyMovie* Inventory::findComedy(const string& title, int year) const {
    return movieList.findComedy(title, year);
}
// End of findComedy()


// ------------------------------------ findDrama() ------------------------------------
// Description:
// Searches for a DramaMovie matching the given director and title.
// Delegates entirely to MovieList::findDrama().
//
// Preconditions:
// director and title are valid strings
//
// Postconditions:
// Returns pointer to matching DramaMovie if found
// Returns nullptr if no match found
// Inventory is unchanged
// --------------------------------------------------------------------------------------------
DramaMovie* Inventory::findDrama(const string& director, const string& title) const {
    return movieList.findDrama(director, title);
}
// End of findDrama()


// ------------------------------------ findClassic() ------------------------------------
// Description:
// Searches for a ClassicMovie matching the given release month, year and actor.
// Delegates entirely to MovieList::findClassic().
//
// Preconditions:
// month and year are valid integers, actor is a valid string
//
// Postconditions:
// Returns pointer to matching ClassicMovie if found
// Returns nullptr if no match found
// Inventory is unchanged
// --------------------------------------------------------------------------------------------
ClassicMovie* Inventory::findClassic(int month, int year, const string& actor) const {
    return movieList.findClassic(month, year, actor);
}
// End of findClassic()


// ------------------------------------ findClassicsByTitle() ------------------------------------
// Description:
// Searches inventory for all available ClassicMovie objects matching
// the given title. Delegates entirely to MovieList::findClassicsByTitle().
//
// Preconditions:
// title is a valid non empty string
//
// Postconditions:
// Returns vector of ClassicMovie pointers with matching title and stock > 0
// Returns empty vector if no matches found
// Inventory is unchanged
// --------------------------------------------------------------------------------------------
vector<ClassicMovie *> Inventory::findClassicsByTitle(const string &title) const {

    return movieList.findClassicsByTitle(title);

}
//End of findClassicsByTitle()

// ------------------------------------ displayInventory() ------------------------------------
// Description:
// Displays all movies in sorted order by genre.
// Delegates entirely to MovieList::display().
// Prints Comedy movies first, Drama second, Classic third.
//
// Preconditions:
// None
//
// Postconditions:
// All movies printed to cout in sorted order by genre
// Inventory is unchanged
// --------------------------------------------------------------------------------------------
void Inventory::displayInventory() const {
    movieList.display();
}
// End of displayInventory()