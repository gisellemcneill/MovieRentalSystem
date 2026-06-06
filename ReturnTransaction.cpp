// ------------------------------------------------ ReturnTransaction.cpp --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

#include "ReturnTransaction.h"
#include "Company.h"
#include "Customer.h"

ReturnTransaction::ReturnTransaction(Movie* movie, int ID) {
	this->type = 'R';
	this->movie = movie;
	this->customerID = ID;
}
ReturnTransaction::ReturnTransaction(const ReturnTransaction& other) {
    this->type = 'R';
    this->movie = other.movie->clone();
    this->customerID = other.customerID;
}

ReturnTransaction::~ReturnTransaction() {
	delete movie;
}


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
	cout << customerID << " is " << "Returning: " << movie->getTitle() << endl; //temp while company is not implemented

	Customer* customer = company.findCustomer(customerID);
	if (customer == nullptr) {
		cerr << "ERROR: Invalid customer ID" << endl;
		return false;
	}

	if (!customer -> validateReturn(movie)){
		cerr << "ERROR: Customer " << customerID <<
			" never borrowed " << movie -> getTitle() << endl;
		return false;
	}

	Movie* real = findInInventory(company);
	if (real == nullptr) {
		cerr << "ERROR: Movie not found in inventory" << endl;
		return false;
	}

	real -> incrementStock();
	return true;

}
//End of execute()

Transaction* ReturnTransaction::clone() const {
    return new ReturnTransaction(*this);
}