// ------------------------------------------------ Customer.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/3/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the Customer class, which represents a customer account in the movie rental customer system.

// Customer functions include:
// Customer(), ~Customer(), addTransaction(), displayHistory()

// --------------------------------------------------------------------------------------------------------------------

#include "Customer.h"

// ------------------------------------ Customer Constructor ------------------------------------
// Description:
// Initializes a Customer object with a given ID, last name, and first name.
//
// Preconditions:
// None
//
// Postconditions:
// Customer object is initialized with the specified customerID, lastName, and firstName.
// The history transaction vector starts empty.
// -------------------------------------------------------------------------------------------------
Customer::Customer(int id, string lName, string fName) : customerID(id), lastName(lName), firstName(fName)  {}
// End of Customer()


// ------------------------------------ Customer Copy Constructor ------------------------------------
// Description:
// Initializes a Customer object copied from a preexisting Customer object "other". Uses 
// polymorphic cloning to perform a deep copy of the transaction history.
//
// Preconditions:
// "other" is a valid Customer object.
//
// Postconditions:
// A new Customer object is initialized with an ID, name, and a deeply copied transaction 
// vector matching "other".
// -------------------------------------------------------------------------------------------------
Customer::Customer(const Customer& other) : customerID(other.customerID), lastName(other.lastName), firstName(other.firstName) {
    for (Transaction* t : other.history) {
        history.push_back(t->clone());
    }
}
// End of Customer()


// ------------------------------------ Customer Destructor ------------------------------------
// Description:
// Destructor ensures proper cleanup and memory management of all dynamically allocated 
// Transaction objects stored in the customer's history.
//
// Preconditions:
// None
//
// Postconditions:
// All Transaction memory owned by this customer is cleanly freed, and the history vector is cleared.
// --------------------------------------------------------------------------------------------
Customer::~Customer() {
    for (Transaction* t : history) {
        delete t;
    }
    history.clear();
}
// End of ~Customer()


// ------------------------------------ getCustomerID ------------------------------------
// Description:
// Retrieves the unique ID integer for the customer.
//
// Preconditions:
// None.
//
// Postconditions:
// Returns the customerID integer.
// --------------------------------------------------------------------------------------------
int Customer::getCustomerID() const {
    return customerID;
}
// End of getCustomerID()


// ------------------------------------ getLastName ------------------------------------
// Description:
// Retrieves the customer's last name.
//
// Preconditions:
// None.
//
// Postconditions:
// Returns the lastName string.
// --------------------------------------------------------------------------------------------
string Customer::getLastName() const {
    return lastName;
}
// End of getLastName()


// ------------------------------------ getFirstName ------------------------------------
// Description:
// Retrieves the customer's first name.
//
// Preconditions:
// None.
//
// Postconditions:
// Returns the firstName string.
// --------------------------------------------------------------------------------------------
string Customer::getFirstName() const {
    return firstName;
}
// End of getFirstName()


// ------------------------------------ addTransaction ------------------------------------
// Description:
// Validates and adds an incoming Transaction pointer to the customer's transaction log calling validateReturn(). 
// Rejects returns if the customer does not currently hold a matching borrowed movie.
//
// Preconditions:
// t points to a valid Transaction object.
//
// Postconditions:
// If validation succeeds, the transaction pointer is added to history, ownership is taken, and returns true.
// If validation fails, returns false.
// --------------------------------------------------------------------------------------------
bool Customer::addTransaction(Transaction* t) {
    if (t->getType() == 'R' && !validateReturn(t->getMovie())) {
        return false;
    }

    history.push_back(t);
    return true;
}
// End of addTransaction()


// ------------------------------------ validateReturn ------------------------------------
// Description:
// Helper verification function that loops through the history log to ensure the customer 
// has an outstanding borrow balance for the specified movie before allowing a return.
//
// Preconditions:
// m points to a valid Movie object.
//
// Postconditions:
// Returns true if the Customer has currently borrowed the movie; otherwise, returns false.
// --------------------------------------------------------------------------------------------
bool Customer::validateReturn(Movie* m) const {
    if (history.empty()) { return false; }

    int count = 0;
    for (Transaction* t : history) {
        if (*(t->getMovie()) == *m) {
            if (t->getType() == 'B') {
                count++;
            } else if (t->getType() == 'R') {
                count--;
            }
        }
    }

    return count > 0;
}
// End of validateReturn()


// ------------------------------------ displayHistory ------------------------------------
// Description:
// Iterates through the customer's log backwards to print out their complete transaction 
// history from newest to oldest.
//
// Preconditions:
// None.
//
// Postconditions:
// Displays all transaction entries via standard output. If history is empty, prints nothing.
// --------------------------------------------------------------------------------------------
void Customer::displayHistory() const {
    if (history.empty()) { return; }

    for (int i = history.size(); i > 0; --i) {
        history[i - 1]->display();
    }
}
// End of displayHistory()


// ------------------------------------ Assignment Operator ------------------------------------
// Description:
// Overloaded assignment operator. Replaces the contents of this Customer object with a 
// deep copy of another preexisting Customer object.
//
// Preconditions:
// "other" is a valid Customer object.
//
// Postconditions:
// Existing transaction memory is completely freed. This object duplicates the IDs, names, 
// and polymorphically clones the log entries of "other". Handles self-assignment safely.
// --------------------------------------------------------------------------------------------
Customer& Customer::operator=(const Customer& other) {
    if (this == &other) { return *this; }
    this->customerID = other.customerID;
    this->lastName = other.lastName;
    this->firstName = other.firstName;

    for (Transaction* t : history) {
        delete t;
    }
    history.clear();

    for (Transaction* t : other.history) {
        history.push_back(t->clone());
    }

    return *this;
}