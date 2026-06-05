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
	Company();
	~Company();

	void loadMovies(string& fileName) const;
	void loadCustomers(string& fileName) const;
	void processCommands(string& fileName) const;

	Inventory* getInventory();

private:
	Inventory inventory;
	CustomerData customers;

	ReturnFactory rFac;
	BorrowFactory bFac;

	MovieFactory mFac;
};

#endif
