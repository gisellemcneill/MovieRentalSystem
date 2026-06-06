// ------------------------------------------------ Transaction.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/31/26

// Date of Last Modification: 6/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the Transaction class, which serves as the abstract base class for all transaction
// types in the movie rental store inventory system.

// Transaction functions include:
// Transaction(), ~Transaction(), operator<<()

//Pure Virtual functions execute() and display() will be implemented by derived classs
// BorrowTransaction and ReturnTransaction

// findInInventory() is a protected helper method used by derived
// classes to locate the corresponding Movie object in the inventory
// using the transaction's stored movie copy as a search key.
// --------------------------------------------------------------------------------------------------------------------

#include "Transaction.h"
#include "ClassicMovie.h"
#include "Company.h"

// ------------------------------------ Transaction Constructor ------------------------------------
// Description:
// Initializes a Transaction object with the given type, movie pointer, and customer ID.
//
// Preconditions:
// movie pointer is valid and not nullptr
//
// Postconditions:
// Transaction object is initialized with provided values
// --------------------------------------------------------------------------------------------
Transaction::Transaction() {

    this->type = 'X';
    this->movie = nullptr;
    this->customerID = 0;

}
// End of Transaction()


// ------------------------------------ getType() ------------------------------------
// Description:
// Returns the type of Transaction
//
// Preconditions:
// Transaction object is initialized
//
// Postconditions:
// Returns type as a char, Transaction object is unchanged
// --------------------------------------------------------------------------------------------
char Transaction::getType() const {
    return type;
}
//End of getType()


// ------------------------------------ getMovie() ------------------------------------
// Description:
// Returns the Movie* of a Transaction
//
// Preconditions:
// Transaction object is initialized
//
// Postconditions:
// Returns movie as a Movie*, Transaction object is unchanged
// --------------------------------------------------------------------------------------------
Movie* Transaction::getMovie() const {
    return movie;
}
//End of getType()


// ------------------------------------ getCustomerID() ------------------------------------
// Description:
// Returns the customerID of a Transaction
//
// Preconditions:
// Transaction object is initialized
//
// Postconditions:
// Returns customerID as an int, Transaction object is unchanged
// --------------------------------------------------------------------------------------------
int Transaction::getCustomerID() const {
    return customerID;
}
//End of getCustomerID()

void Transaction::display(ostream& out) const {
    out << type << " " << movie->getTitle() << endl;
}

// ------------------------------------ operator<< ------------------------------------
// Description:
// Overloads the << operator to print a Transaction object to an output stream.
// Calls the pure virtual display() function for polymorphic behavior,
// ensuring the correct derived class display format is used.
//
// Preconditions:
// Transaction object is initialized
//
// Postconditions:
// Transaction information is printed to the output stream
// Returns reference to ostream for chaining
// --------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Transaction* t) {

    t->display(out);
    return out;

}
//End of operator<<()


// ------------------------------------ findInInventory() ------------------------------------
// Description:
// Protected helper method that searches the inventory for the real Movie object
// corresponding to this transaction's stored movie copy.
// Uses the movie's genre to determine which genre specific find method to call.
// For ClassicMovie uses static_cast which is safe since genre is already verified.
//
// Preconditions:
// movie pointer is valid and not nullptr
// company is a valid reference to the running Company instance
//
// Postconditions:
// Returns pointer to the real inventory Movie object if found
// Returns nullptr if movie is not found in inventory
// Inventory and transaction are unchanged
// --------------------------------------------------------------------------------------------
Movie* Transaction::findInInventory(Company &company) const {

    if (movie -> getGenre() == 'F') {

        return company.getInventory().findComedy(movie -> getTitle(), movie -> getYear());

    } else if (movie -> getGenre() == 'D'){

        return company.getInventory().findDrama(movie -> getDirector(), movie -> getTitle());

    }else if (movie -> getGenre() == 'C') {

        //ClassicMovie has extra fields than movie, so need to static cast
        ClassicMovie* classic = static_cast<ClassicMovie*>(movie);

        return company.getInventory().findClassic(classic -> getReleaseMonth(),
            classic -> getYear(), classic -> getMajorActor());

        }

        return nullptr;

    }
//End of findInInventory

