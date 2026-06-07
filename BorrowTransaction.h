// ------------------------------------------------ BorrowTransaction.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the BorrowTransaction class, a derived class of the abstract Transaction class which handles
// the behavior of a borrow command and can be stored in a customers history

// BorrowTransaction supports polymorphism by overriding methods from the base Transaction class
// A BorrowTransaction can be instatiated dynamically through the TransactionFactory class, following the
// Factory Method Pattern

// --------------------------------------------------------------------------------------------------------------------

#ifndef BORROWTRANSACTION_H
#define BORROWTRANSACTION_H

#include "Transaction.h"

class BorrowTransaction : public Transaction {
public:
	BorrowTransaction(Movie* movie, int ID);
    BorrowTransaction(const BorrowTransaction& other);
	~BorrowTransaction();

    Transaction* clone() const;
    
	bool execute(Company& company);
};

#endif