#include "TransactionFactory.h"
#include "ReturnTransaction.h"
#include "BorrowTransaction.h"

Transaction* ReturnFactory::createTransaction(Movie* movie, int ID) const {
	return new ReturnTransaction(movie, ID);
}
Transaction* BorrowFactory::createTransaction(Movie* movie, int ID) const {
	return new BorrowTransaction(movie, ID);
}