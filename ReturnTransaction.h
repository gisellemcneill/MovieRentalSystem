// ------------------------------------------------ ReturnTransaction.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the ReturnTransaction class, a derived class of the abstract Transaction class which handles
// the behavior of a borrow command and can be stored in a customers history

// ReturnTransaction supports polymorphism by overriding methods from the base Transaction class
// A ReturnTransaction can be instatiated dynamically through the TransactionFactory class, following the
// Factory Method Pattern

// --------------------------------------------------------------------------------------------------------------------

#ifndef RETURNTRANSACTION_H
#define RETURNTRANSACTION_H

#include "Transaction.h"

class ReturnTransaction : public Transaction {
public:
	ReturnTransaction(Movie* movie, int ID);
    ReturnTransaction(const ReturnTransaction& other);
	~ReturnTransaction();

    Transaction* clone() const;

	bool execute(Company& company);
};

#endif