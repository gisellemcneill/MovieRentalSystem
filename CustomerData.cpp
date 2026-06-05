// ------------------------------------------------ CustomerData.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/2/26

// Date of Last Modification: 6/05/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the CustomerData class, which implements a custom open-addressing Hashtable to store and manage
// Customer objects for the movie rental customer system.

// CustomerData functions include:
// CustomerData(), ~CustomerData(), addCustomer(), getCustomer()

// --------------------------------------------------------------------------------------------------------------------

#include "CustomerData.h"

// ------------------------------------ CustomerData Constructor ------------------------------------
// Description:
// Initializes a CustomerData object with a default capacity and an array of Customer
// object pointers.
//
// Preconditions:
// None
//
// Postconditions:
// CustomerData object is initialized with a default capacity of 7, size of 0, and
// empty array of size 7.
// -------------------------------------------------------------------------------------------------
CustomerData::CustomerData() : capacity(7), size(0) {
    table = new Customer*[capacity]();
}
// End of CustomerData()


// ------------------------------------ CustomerData Copy Constructor ------------------------------------
// Description:
// Initializes a CustomerData object copied from a prexisting CustomerData object "other".
//
// Preconditions:
// "other" is a valid CustomerData object.
//
// Postconditions:
// A new CustomerData object is initialized with a capacity, size, and content matching "other".
// -------------------------------------------------------------------------------------------------
CustomerData::CustomerData(const CustomerData& other) : capacity(other.capacity), size(other.size) {
    table = new Customer*[capacity]();
    for (int i = 0; i < capacity; i++) {
        if (other.table[i] != nullptr) {
            table[i] = new Customer(*other.table[i]);
        }
    }
}
// End of CustomerData()


// ------------------------------------ CustomerData Destructor ------------------------------------
// Description:
// Destructor ensures proper cleanup and memory management of the table array
// and Customer objects when deletion happens
//
// Preconditions:
// None
//
// Postconditions:
// All class owned data is deleted and pointers are handled
// --------------------------------------------------------------------------------------------
CustomerData::~CustomerData() {
    for (int i = 0; i < capacity; i++) {
        delete table[i];
    }

    delete[] table;
}
// End of ~CustomerData()


// ------------------------------------ addCustomer ------------------------------------
// Description:
// Creates a new Customer object and adds it to the hashtable if the customer does not
// already exist by calling insert(). Automatically resizes the table if the load factor 
// exceeds 50% by calling resize().
//
// Preconditions:
// None.
//
// Postconditions:
// If the ID is unique, a new Customer is allocated and inserted, and size increments by 1.
// If the load factor limits are hit, the table capacity is expanded.
// --------------------------------------------------------------------------------------------
void CustomerData::addCustomer(int ID, string lName, string fName) {
    if (getCustomer(ID) != nullptr) { return; }
    if ((size + 1) * 2 > capacity) {
        resize();
    }

    Customer* customer = new Customer(fName, lName, ID);

    insert(ID, customer);
    size++;
}
// End of addCustomer()


// ------------------------------------ insert ------------------------------------
// Description:
// Helper method that inserts a Customer pointer into the table array using double hashing
// to resolve collisions.
//
// Preconditions:
// "customer" points to a valid Customer object matching the provided ID. Size <= capacity/2 
// and ID is unique
//
// Postconditions:
// The customer pointer is placed into the first available open slot determined by hashing.
// --------------------------------------------------------------------------------------------
void CustomerData::insert(int ID, Customer* customer) {
    int index = hash1(ID);
    int i = 0;

    while (table[index] != nullptr) {
        i++;
        index = collision(ID, i);
    }

    table[index] = customer;
}
// End of insert()


// ------------------------------------ getCustomer ------------------------------------
// Description:
// Searches the hashtable for a Customer with the matching ID using double hashing.
//
// Preconditions:
// None.
//
// Postconditions:
// Returns a pointer to the matching Customer object if found; otherwise, returns nullptr.
// --------------------------------------------------------------------------------------------
Customer* CustomerData::getCustomer(int ID) {
    if (size == 0) { return nullptr; }

    int index = hash1(ID);
    int i = 0;

    while (table[index] != nullptr) {
        if (table[index]->getCustomerID() == ID) {
            return table[index];
        }
        i++;
        index = collision(ID, i);
    }

    return nullptr;
}
// End of getCustomer()


// ------------------------------------ hash1 ------------------------------------
// Description:
// Primary hash function. Computes the initial table index based on the customer ID.
//
// Preconditions:
// None.
//
// Postconditions:
// Returns a valid index integer between 0 and capacity - 1.
// --------------------------------------------------------------------------------------------
int CustomerData::hash1(int ID) const {
    return ID % capacity;
}
// End of hash1()


// ------------------------------------ hash2 ------------------------------------
// Description:
// Secondary hash function. Calculates the step used during collisions.
//
// Preconditions:
// None.
//
// Postconditions:
// Returns a positive step-size integer != 0.
// --------------------------------------------------------------------------------------------
int CustomerData::hash2(int ID) const {
    return 5 - (ID % 5);
}
// End of hash2()


// ------------------------------------ collision ------------------------------------
// Description:
// Computes the next probed index using the double hashing formula.
//
// Preconditions:
// i > 0 
//
// Postconditions:
// Returns an integer within the bounds of the table capacity.
// --------------------------------------------------------------------------------------------
int CustomerData::collision(int ID, int i) const {
    return (hash1(ID) + i * hash2(ID)) % capacity;
}
// End of collision()


// ------------------------------------ nextPrime ------------------------------------
// Description:
// Finds the next appropriate prime capacity from a pre-defined list that is at least
// twice the size of the current capacity.
//
// Preconditions:
// The static primes vector contains tracking values.
//
// Postconditions:
// Returns a prime integer greater than capacity * 2. If limit exceeded, returns maximum listed prime.
// --------------------------------------------------------------------------------------------
int CustomerData::nextPrime() const {
    for (int num : primes) {
        if (num > capacity * 2) {
            return num;
        }
    }

    return primes.at(primes.size() - 1);
}
// End of nextPrime()


// ------------------------------------ resize ------------------------------------
// Description:
// Expands the table capacity to a larger prime number, reallocates the pointer array, 
// and re-hashes all existing valid elements into the new positions.
//
// Preconditions:
// None.
//
// Postconditions:
// The table capacity is increased, all Customer elements are transferred without losing data, 
// and old array memory is cleanly freed. Returns true upon completion.
// --------------------------------------------------------------------------------------------
bool CustomerData::resize() {
    int lastCapacity = capacity;
    Customer** lastTable = table;

    capacity = nextPrime();
    table = new Customer*[capacity]();

    for (int i = 0; i < lastCapacity; i++) {
        if (lastTable[i] != nullptr) {
            insert(lastTable[i]->getCustomerID(), lastTable[i]);
        }
    }

    delete[] lastTable;
    return true;
}
// End of resize()


// ------------------------------------ operator= ------------------------------------
// Description:
// Overloaded assignment operator. Safely replaces the contents of this CustomerData object 
// with a deep copy of another preexisting CustomerData object.
//
// Preconditions:
// "other" is a valid CustomerData object.
//
// Postconditions:
// Existing memory is cleared. This object becomes an independent duplicate of "other", 
// returning a reference to itself. Handles self-assignment safely.
// --------------------------------------------------------------------------------------------
CustomerData& CustomerData::operator=(const CustomerData& other) {
    if (this == &other) { return *this; }
    
    for (int i = 0; i < capacity; i++) {
        delete table[i];
    }
    delete[] table;

    this->capacity = other.capacity;
    this->size = other.size;
    this->table = new Customer*[capacity]();

    for (int i = 0; i < capacity; i++) {
        if (other.table[i] != nullptr) {
            table[i] = new Customer(*other.table[i]);
        }
    }

    return *this;
}