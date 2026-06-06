// ------------------------------------------------ BorrowTransaction.cpp --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

#include "BorrowTransaction.h"
#include "Company.h"
#include "ClassicMovie.h"
#include "Customer.h"

BorrowTransaction::BorrowTransaction(Movie* movie, int ID) {
	this->type = 'B';
	this->movie = movie;
	this->customerID = ID;
}
BorrowTransaction::BorrowTransaction(const BorrowTransaction& other) {
    this->type = 'B';
    this->movie = other.movie->clone();
    this->customerID = other.customerID;
}

BorrowTransaction::~BorrowTransaction() {
    delete movie;
}


// ------------------------------------ execute() ------------------------------------------
// Description:
// Executes a borrow transaction by finding the real Movie object in inventory
// and decrementing its stock by 1. If the movie is out of stock an error
// message is displayed. For ClassicMovies, available alternative actors
// are suggested when the requested actor version is out of stock.
// Uses findInInventory() helper to locate the real inventory movie.
//
// Preconditions:
// company is a valid reference to the running Company instance
// movie pointer is valid and not nullptr
//
// Postconditions:
// Returns true and decrements real inventory movie stock by 1 if successful
// Returns false and prints error if movie not found or out of stock
// Customer history and inventory unchanged if unsuccessful
// --------------------------------------------------------------------------------------------
bool BorrowTransaction::execute(Company& company) {

    Movie* real = findInInventory(company);
    //Movie is valid and found check

    if (real == nullptr) {
        cout << "ERROR: Movie not found" << "\n" << flush;
        return false;
    }

    bool success = real -> decrementStock();
    if (!success) {
        cout << "ERROR: " << movie -> getTitle() <<
            " is out of stock." << "\n" << flush;

        if (movie -> getGenre() == 'C') {
            ClassicMovie* classic = static_cast<ClassicMovie*>(movie);
            vector<ClassicMovie*> alternatives =
                company.getInventory().findClassicsByTitle(classic -> getTitle());

            if (!alternatives.empty()) {
                cout << "Available alternative: " << endl;
                for (ClassicMovie* c : alternatives) {
                    cout << " " << c -> getMajorActor() << endl;
                }
            }else {
                cout << "ERROR: No copies of: " << classic -> getTitle()
                << " with a different major actor are available." << "\n" << flush;
            }
        }
        return false;
    }
    return true;
}
//End of execute()

Transaction* BorrowTransaction::clone() const {
    return new BorrowTransaction(*this);
}

