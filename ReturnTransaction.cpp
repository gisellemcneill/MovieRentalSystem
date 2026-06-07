// ------------------------------------------------ ReturnTransaction.cpp --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the ReturnTransaction class, a derived class of the abstract Transaction class which handles
// the behavior of a borrow command and can be stored in a customers history

// ReturnTransaction functions include:
// ReturnTransaction(), ~ReturnTransaction(), execute(), operator<<()

// ReturnTransaction supports polymorphism by overriding methods from the base Transaction class
// A ReturnTransaction can be instatiated dynamically through the TransactionFactory class, following the
// Factory Method Pattern

// --------------------------------------------------------------------------------------------------------------------

#include "ReturnTransaction.h"
#include "Company.h"
#include "Customer.h"

// ------------------------------------ ReturnTransaction Constructor ------------------------------------
// Description:
// Initializes a ReturnTransaction object with the given movie and customer ID, sets
// type to 'R' for a return transaction.
//
// Preconditions:
// None
//
// Postconditions:
// ReturnTransaction object is initialized with provided values and type set to 'R'
// --------------------------------------------------------------------------------------------
ReturnTransaction::ReturnTransaction(Movie* movie, int ID) {
	this->type = 'R';
	this->movie = movie;
	this->customerID = ID;
}
//End of ReturnTransaction Constructor


// ------------------------------------ ReturnTransaction Copy Constructor ------------------------------------
// Description:
// Instantiates this ReturnTransaction as a copy of a prexisting ReturnTransaction
//
// Preconditions:
// None
//
// Postconditions:
// ReturnTransaction object is initialized with matching values and type set to 'R'
// --------------------------------------------------------------------------------------------
ReturnTransaction::ReturnTransaction(const ReturnTransaction& other) {
    this->type = 'R';
    this->movie = other.movie->clone();
    this->customerID = other.customerID;
}
//End of ReturnTransaction Copy Constructor


// ------------------------------------ ReturnTransaction Destructor ------------------------------------
// Description:
// Destructor ensures proper cleanup and memory management of the dynamically allocated
// Movie object in ReturnTransaction
//
// Preconditions:
// none
//
// Postconditions:
// The Movie memory owned by this Transaction is cleanly freed.
// --------------------------------------------------------------------------------------------
ReturnTransaction::~ReturnTransaction() {
	delete movie;
}
//End of ReturnTransaction Destructor


// ------------------------------------ execute() ------------------------------------
// Description:
// Executes a return transaction by verifying the customer previously borrowed
// the movie, then finding the real Movie object in inventory and incrementing
// its stock by 1. If the customer never borrowed the movie an error is displayed.
// Uses findInInventory() helper to locate the real inventory movie.
//
// Preconditions:
// company is a valid reference to the running Company instance
// movie pointer is valid and not nullptr
//
// Postconditions:
// Returns true and increments real inventory movie stock by 1 if successful
// Returns false and prints error if movie not found or never borrowed
// Customer history and inventory unchanged if unsuccessful
// --------------------------------------------------------------------------------------------
bool ReturnTransaction::execute(Company& company) {

	Customer* customer = company.findCustomer(customerID);
	if (customer == nullptr) {
		cout << "ERROR: Invalid customer ID" << "\n" << flush;
		return false;
	}

	if (!customer -> validateReturn(movie)){
		cout << "ERROR: Customer " << customerID <<
			" never borrowed " << movie -> getTitle() << "\n" << flush;
		return false;
	}

	Movie* real = findInInventory(company);
	if (real == nullptr) {
		cout << "ERROR: Movie not found in inventory" << "\n" << flush;
		return false;
	}

	real -> incrementStock();
	return true;

}
//End of execute()


// ------------------------------------ clone() ------------------------------------------
// Description:
// Creates a clone of the current ReturnTransaction, calling the copy constructor 
// and returning the object polymorphically cast as a generic Transaction.
//
// Preconditions:
// none
//
// Postconditions:
// Returns a valid pointer to a BorrowTransaction object matching this
// --------------------------------------------------------------------------------------------
Transaction* ReturnTransaction::clone() const {
    return new ReturnTransaction(*this);
}
//End of clone()