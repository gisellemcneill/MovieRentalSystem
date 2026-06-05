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

	void loadMovies(string& fileName);
	void loadCustomers(string& fileName);
	void processCommands(string& fileName);

	Inventory* getInventory();

private:
	Inventory inventory;
	CustomerData customers;

	BorrowFactory bFac;
	ReturnFactory rFac;

	MovieFactory mFac;
};

#endif
