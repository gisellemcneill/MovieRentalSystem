#include <iostream>
#include "Company.h"

using namespace std;

int main() {

    Company store;

    store.loadMovies("data4movies.txt");
    store.loadCustomers("data4customers.txt");
    store.processCommands("data4commands.txt");

    return 0;
}