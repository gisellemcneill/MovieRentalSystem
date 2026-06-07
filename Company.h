// ------------------------------------------------ Company.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/05/26

// Date of Last Modification: 6/6/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Declares the Company class, which parses, formats, and directs input for the program and produces output. 

// --------------------------------------------------------------------------------------------------------------------

#ifndef COMPANY_H
#define COMPANY_H

#include "Inventory.h"
#include "CustomerData.h"
#include "TransactionFactory.h"
#include "MovieFactory.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Company {
public:
	//constructor
	Company();
	~Company();

	//file loading functions
	bool loadMovies(const string& fileName);
	bool loadCustomers(const string& fileName);
	bool processCommands(const string& fileName);

	Customer* findCustomer(int id); //return a customer
	Inventory& getInventory(); //return a inventory

private:
	Inventory inventory;
	CustomerData customers;

	BorrowFactory bFac;
	ReturnFactory rFac;

	MovieFactory mFac;
};

#endif
