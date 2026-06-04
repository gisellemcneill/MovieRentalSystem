// ------------------------------------------------ InventoryTests.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/1/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Tests the Inventory class and its interaction with MovieList.
// All test data matches data4movies.txt exactly.
// Tests cover simple functionality, hard cases, and edge cases
// including adding movies, finding movies, stock management,
// and display formatting.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "Inventory.h"

using namespace std;

// ------------------------------------ printDivider() ------------------------------------
// Description: prints a divider line for test readability
// --------------------------------------------------------------------------------------------
void printDivider(const string& testName) {
    cout << "\n" << string(60, '-') << endl;
    cout << "TEST: " << testName << endl;
    cout << string(60, '-') << endl;
}

int main() {

    printDivider("Add one of each genre and display inventory");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Annie Hall", "Woody Allen", 1977, 10));
        inv.addMovie(new DramaMovie("Schindler's List", "Steven Spielberg", 1993, 10));
        inv.addMovie(new ClassicMovie("Casablanca", "Michael Curtiz", 8, 1942, 10, "Humphrey Bogart"));

        inv.displayInventory();
    }

    printDivider("Find existing movies");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 10));
        inv.addMovie(new DramaMovie("Good Will Hunting", "Gus Van Sant", 2000, 10));
        inv.addMovie(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Katherine Hepburn"));

        cout << (inv.findComedy("Fargo", 1996) != nullptr ? "PASS" : "FAIL") << endl;
        cout << (inv.findDrama("Gus Van Sant", "Good Will Hunting") != nullptr ? "PASS" : "FAIL") << endl;
        cout << (inv.findClassic(9, 1938, "Katherine Hepburn") != nullptr ? "PASS" : "FAIL") << endl;
    }

    printDivider("Find missing movie");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 10));

        if (inv.findComedy("Fake Movie", 2000) == nullptr) {
            cout << "PASS: Missing movie returned nullptr" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }

    printDivider("Borrow movie");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 10));

        ComedyMovie* movie = inv.findComedy("Fargo", 1996);

        cout << "Before borrow: " << movie->getStock() << endl;
        movie->decrementStock();
        cout << "After borrow: " << movie->getStock() << endl;
    }

    printDivider("Return movie");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Annie Hall", "Woody Allen", 1977, 10));

        ComedyMovie* movie = inv.findComedy("Annie Hall", 1977);

        movie->decrementStock();
        movie->incrementStock();

        cout << "Stock after return: " << movie->getStock() << endl;
    }

    printDivider("Borrow to zero");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 1));

        ComedyMovie* movie = inv.findComedy("Fargo", 1996);

        bool firstBorrow = movie->decrementStock();
        bool secondBorrow = movie->decrementStock();

        cout << "Stock: " << movie->getStock() << endl;

        if (firstBorrow && !secondBorrow) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }

    printDivider("Comedy sorting");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("You've Got Mail", "Nora Ephron", 1998, 10));
        inv.addMovie(new ComedyMovie("Annie Hall", "Woody Allen", 1977, 10));
        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 10));
        inv.addMovie(new ComedyMovie("Sleepless in Seattle", "Nora Ephron", 1993, 10));

        inv.displayInventory();
    }

    printDivider("Duplicate movie insertion");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 10));
        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 5));

        inv.displayInventory();
    }

    printDivider("Same classic different actors");
    {
        Inventory inv;

        inv.addMovie(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Katherine Hepburn"));
        inv.addMovie(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Cary Grant"));

        ClassicMovie* hepburn = inv.findClassic(9, 1938, "Katherine Hepburn");
        ClassicMovie* grant = inv.findClassic(9, 1938, "Cary Grant");

        if (hepburn != nullptr && grant != nullptr) {
            cout << "PASS: Both actors found" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }

    printDivider("Borrow one classic does not affect another");
    {
        Inventory inv;

        inv.addMovie(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Katherine Hepburn"));
        inv.addMovie(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Cary Grant"));

        ClassicMovie* hepburn = inv.findClassic(9, 1938, "Katherine Hepburn");
        ClassicMovie* grant = inv.findClassic(9, 1938, "Cary Grant");

        hepburn->decrementStock();

        cout << "Hepburn stock: " << hepburn->getStock() << endl;
        cout << "Grant stock: " << grant->getStock() << endl;

        if (grant->getStock() == 10) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }

    printDivider("Reverse order insertion");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("You've Got Mail", "Nora Ephron", 1998, 10));
        inv.addMovie(new ComedyMovie("Sleepless in Seattle", "Nora Ephron", 1993, 10));
        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 10));
        inv.addMovie(new ComedyMovie("Annie Hall", "Woody Allen", 1977, 10));

        inv.displayInventory();
    }

    printDivider("Empty inventory");
    {
        Inventory inv;

        inv.displayInventory();

        cout << "PASS: No crash on empty inventory" << endl;
    }

    cout << "\n" << string(60, '-') << endl;
    cout << "All Inventory tests complete" << endl;
    cout << string(60, '-') << endl;

    printDivider("Wrong search key");
    {
        Inventory inv;

        inv.addMovie(new ComedyMovie("Fargo", "Joel Coen", 1996, 10));

        if (inv.findComedy("Fargo", 1995) == nullptr) {
            cout << "PASS" << endl;
        }
        else {
            cout << "FAIL" << endl;
        }
    }


    return 0;
}