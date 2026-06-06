// ------------------------------------------------ Transaction.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 5/31/26

// Date of Last Modification: 6/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the Transaction class, which serves as the abstract base class for all transaction types in the
// movie rental store inventory system. Transaction will declare shared methods and attributes for derived
// transaction classes, including type, movie, customer

// Transaction object pointers will be stored in the customer class for the transaction history
// Transactions will also be used to execute commands by the Company class on the inventory system.

// The class uses a virtual destructor to ensure proper memory cleanup when deleting derived
// class objects through a base class pointer. Derived classes will include BorrowTransaction and
// ReturnTransaction must implement the pure virtual functions execute() and display()

// findInInventory() is a protected helper method used by derived
// classes to locate the corresponding Movie object in the inventory
// using the transaction's stored movie copy as a search key.
// --------------------------------------------------------------------------------------------------------------------


#ifndef PROGRAM4_TRANSACTION_H
#define PROGRAM4_TRANSACTION_H

#include <iostream>
#include "Movie.h"

using namespace std;

class Company;

class Transaction {
public:
    //constructor
    Transaction();
    virtual ~Transaction() = default; //virtual destructor

    virtual Transaction* clone() const = 0; //virtual clone function

    //getters
    char getType() const;
    Movie* getMovie() const;
    int getCustomerID() const;

    virtual bool execute(Company& company) = 0;
    void display(ostream& out) const;

    //To be used with display
    friend ostream& operator<<(ostream& out, const Transaction* t);

protected:
    char type;
    Movie* movie;
    int customerID;

    //helper method for locating movie in Inventory
    Movie* findInInventory(Company& company) const;
};

#endif //PROGRAM4_TRANSACTION_H