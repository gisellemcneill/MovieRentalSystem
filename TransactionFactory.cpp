// ------------------------------------------------ TransactionFactory.cpp --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/04/26

// Date of Last Modification: 6/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// The factory classes used to build the derived classes of the abstract Transaction class at runtime. Allows for
// the derived Transaction classes to be treated polymorphically and cast under the generic Transaction type. Follows
// the Factory Method pattern with a simple factory.

// Includes the abstract TransactionFactory class, concrete ReturnFactory class, and concrete BorrowFactory class

// --------------------------------------------------------------------------------------------------------------------

#include "TransactionFactory.h"
#include "ReturnTransaction.h"
#include "BorrowTransaction.h"
#include "Transaction.h"
#include "Movie.h"

// ------------------------------------ ReturnFactory::createTransaction() ------------------------------------
// Description:
// Builds a ReturnTransaction object with the given Movie pointer, and customer ID, by calling
// the ReturnTransaction copy constructor and casting it under the base Transaction class for polymorphism
//
// Preconditions:
// movie pointer is valid and not nullptr
//
// Postconditions:
// Returns a ReturnTransaction object under generic type Transaction
// --------------------------------------------------------------------------------------------
Transaction* ReturnFactory::createTransaction(Movie* movie, int ID) const {
	return new ReturnTransaction(movie, ID);
}
//End of ReturnFactory::createTransaction()


// ------------------------------------ BorrowFactory::createTransaction() ------------------------------------
// Description:
// Builds a BorrowFactory object with the given Movie pointer, and customer ID, by calling
// the BorrowFactory copy constructor and casting it under the base Transaction class for polymorphism
//
// Preconditions:
// movie pointer is valid and not nullptr
//
// Postconditions:
// Returns a BorrowFactory object under generic type Transaction
// --------------------------------------------------------------------------------------------
Transaction* BorrowFactory::createTransaction(Movie* movie, int ID) const {
	return new BorrowTransaction(movie, ID);
}
//End of BorrowFactory::createTransaction()