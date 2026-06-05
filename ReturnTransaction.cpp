// ------------------------------------------------ ReturnTransaction.cpp --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

#include "ReturnTransaction.h"

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

bool ReturnTransaction::execute(Company& company) {
	cout << customerID << " is " << "Returning: " << movie->getTitle() << endl; //temp while company is not implemented
}

Transaction* ReturnTransaction::clone() const {
    return new ReturnTransaction(*this);
}