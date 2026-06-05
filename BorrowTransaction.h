// ------------------------------------------------ BorrowTransaction.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/4/26

// Date of Last Modification: 6/5/26

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