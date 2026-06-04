// ------------------------------------------------ Transaction.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/31/26

// Date of Last Modification: 5/31/26

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
Transaction::Transaction(char type, Movie *movie, int customerID) {

    this->type = type;
    this->movie = new Movie(*other.movie);
    this->customerID = customerID;

}
// End of Transaction()


// ------------------------------------ Transaction Copy Constructor ------------------------------------
// Description:
// Initializes a Transaction object with the given type, movie pointer, and customer ID.
//
// Preconditions:
// movie pointer is valid and not nullptr
//
// Postconditions:
// Transaction object is initialized with provided values
// --------------------------------------------------------------------------------------------
Transaction::Transaction(const Transaction& other) {

    this->type = other.type;
    this->movie = new Movie(*other.movie);
    this->customerID = other.customerID;

}
// End of Transaction()


// ------------------------------------ Transaction Destructor ------------------------------------
// Description:
// Virtual destructor ensures proper cleanup of derived class objects
// when deleted through a base class pointer.
//
// Preconditions:
// None
//
// Postconditions:
//The derived class destructor is called before the base class destructor
// --------------------------------------------------------------------------------------------
Transaction::~Transaction() {
    delete movie;
}
//End of ~Transaction()


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
ostream& operator<<(ostream& out, const Transaction& t) {

    t.display(out);
    return out;

}
//End of operator<<()


// ------------------------------------ Transaction Assignment Operator ------------------------------------
// Description:
// Initializes a Transaction object with the given type, movie pointer, and customer ID.
//
// Preconditions:
// movie pointer is valid and not nullptr
//
// Postconditions:
// Transaction object is initialized with provided values
// --------------------------------------------------------------------------------------------
Transaction& Transaction::Transaction(const Transaction& other) {
    if (this == &other) { return *this; }
    delete movie;

    this->type = other.type;
    this->movie = new Movie(*other.movie);
    this->customerID = other.customerID;

    return *this;
}
// End of Transaction()
