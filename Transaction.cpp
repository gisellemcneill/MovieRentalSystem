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
// --------------------------------------------------------------------------------------------------------------------

#include "Transaction.h"

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
