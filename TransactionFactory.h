// ------------------------------------------------ TransactionFactory.h --------------------------------------------------------

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

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

//forward references
class Transaction;
class Movie;

// ------------------------------------------------ TransactionFactory Class ------------------------------------------

// Purpose:
// The generic abstract TransactionFactory class used to declare the ability to build and return a Transaction object 

// --------------------------------------------------------------------------------------------------------------------
class TransactionFactory {
public:
	//virtual Transaction builder
	virtual Transaction* createTransaction(Movie* movie, int ID) const = 0;
};
//End of TransactionFactory class


// ------------------------------------------------ ReturnFactory Class ------------------------------------------

// Purpose:
// The concrete derived ReturnFactory class of the base TransactionFactory class used to declare 
// the ability to build and return a ReturnTransaction object 

// --------------------------------------------------------------------------------------------------------------------
class ReturnFactory : public TransactionFactory {
public:
	//concrete ReturnTransaction builder
	Transaction* createTransaction(Movie* movie, int ID) const override;
};
//End of ReturnFactory class


// ------------------------------------------------ BorrowFactory Class ------------------------------------------

// Purpose:
// The concrete derived BorrowFactory class of the base TransactionFactory class used to declare 
// the ability to build and return a BorrowTransaction object 

// --------------------------------------------------------------------------------------------------------------------
class BorrowFactory : public TransactionFactory {
public:
	//concrete BorrowTransaction builder
	Transaction* createTransaction(Movie* movie, int ID) const override;
};
//End of BorrowFactory class

#endif