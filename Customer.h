// ------------------------------------------------ Customer.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the Customer class, which represents a customer account in the movie rental customer system.

// Customer object pointers will be stored in the custom CustomerData Hashtable. A Customer object stores Transaction
// object pointers represeting a customers' transaction history.

// The class uses a manual destructor to ensure proper memory cleanup when upon deletion and follows the
// Rule of Three with an overridden copy constructor and assignment operator. A Customer can add to and display
// its history.
// --------------------------------------------------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"
#include "Movie.h"

using namespace std;

class Customer {
public:
    //constructor
    Customer(string firstName, string lastName, int id);
    Customer(const Customer& other);
    ~Customer();

    //getters
    int getCustomerID() const;
    string getLastName() const;
    string getFirstName() const;

    bool addTransaction(Transaction* t);
    void displayHistory(ostream& out) const;

    friend ostream& operator<<(ostream& out, const Customer* c);
    //assignment operator
    Customer& operator=(const Customer& other);
private:
    int customerID;
    string lastName;
    string firstName;

    vector<Transaction*> history;

    //helper for addTransaction
    bool validateReturn(Movie* m) const;
};

#endif