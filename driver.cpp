#include <iostream>
#include "Company.h"

using namespace std;

int main() {

    Company store;

    store.loadMovies("data4movies.txt");
    store.loadCustomers("data4customers.txt");
    store.processCommands("data4commands.txt");

    Company store1;

    store1.loadMovies("data4movies_edge.txt");
    store1.loadCustomers("data4customers_edge.txt");
    store1.processCommands("data4commands_edge.txt");

    return 0;
}