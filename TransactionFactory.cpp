#include "TransactionFactory.h"
#include "ReturnTransaction.h"
#include "BorrowTransaction.h"
#include "Transaction.h"
#include "Movie.h"

Transaction* ReturnFactory::createTransaction(Movie* movie, int ID) const {
	return new ReturnTransaction(movie, ID);
}
Transaction* BorrowFactory::createTransaction(Movie* movie, int ID) const {
	return new BorrowTransaction(movie, ID);
}