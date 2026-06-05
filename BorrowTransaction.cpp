// ------------------------------------------------ BorrowTransaction.cpp --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

#include "BorrowTransaction.h"

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

bool BorrowTransaction::execute(Company& company) {
    cout << customerID << " is " << "Borrowing: " << movie->getTitle() << endl; //temp while company is not implemented
}

Transaction* BorrowTransaction::clone() const {
    return new BorrowTransaction(*this);
}

