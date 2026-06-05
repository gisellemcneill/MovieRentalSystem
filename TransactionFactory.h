#pragma once

#include "Transaction.h"

class TransactionFactory {
public:
	virtual Transaction* createTransaction(Movie* movie, int ID) const = 0;
};

class ReturnFactory : public TransactionFactory {
public:
	Transaction* createTransaction(Movie* movie, int ID) const override;
};

class BorrowFactory : public TransactionFactory {
public:
	Transaction* createTransaction(Movie* movie, int ID) const override;
};
