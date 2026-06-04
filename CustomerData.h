// ------------------------------------------------ CustomerData.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/2/26

// Date of Last Modification: 6/3/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the CustomerData class, which implements a custom open-addressing Hashtable to store and manage
// Customer objects for the movie rental customer system.

// CustomerData uses Double Hashing to handle collisions, tracking objects via a dynamically allocated array
// of Customer object pointers. To optimize performance and maintain low load, the table dynamically
// resizes its capacity to the next available prime number once its size passes 50% of capacity.

// The class uses a manual destructor to ensure proper memory cleanup of all allocated Customer pointers upon
// deletion and follows the Rule of Three with an overridden copy constructor and assignment operator.
// --------------------------------------------------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Customer.h"

using namespace std;

class CustomerData {
public:
    //constructors
    CustomerData();
    CustomerData(const CustomerData& other);
    ~CustomerData();

    void addCustomer(int ID, string lName, string fName);
    Customer* getCustomer(int ID);

    //assignment operator
    CustomerData& operator=(const CustomerData& other);
private:
    Customer** table;
    int capacity;
    int size;

    //prime numbers for capacity setting
    inline static const vector<int> primes = {
        7, 17, 37, 79, 163, 331, 673, 1361, 2729, 5471, 10949
    };

    //helper for addCustomer()
    void insert(int ID, Customer* c);

    //hash algorithm functions
    int hash1(int ID) const;
    int hash2(int ID) const;
    int collision(int ID, int collisions) const;

    //helpers for resizing
    int nextPrime() const;
    bool resize();  

};

#endif