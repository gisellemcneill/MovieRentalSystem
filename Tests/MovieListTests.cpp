// ------------------------------------------------ MovieListTests.cpp ------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/1/26

// --------------------------------------------------------------------------------------------------------------------
//
// Purpose:
// This file contains unit and stress tests for the MovieList class in the Program 4
// movie rental inventory system.
//
// The tests validate:
// - Correct insertion of Comedy, Drama, and Classic movies
// - Proper sorting behavior within each genre
// - Correct handling of duplicate movie entries (especially Classic movies with multiple actors)
// - Accurate stock tracking per movie instance
// - Proper grouping and display formatting for inventory output
//
// This file is used to verify that MovieList correctly manages dynamic Movie objects,
// maintains genre-based ordering, and supports expected inventory behavior under stress conditions.
//
// --------------------------------------------------------------------------------------------------------------------

//Only question is whether actor ordering display needs to be alphabetical or input order specific

#include <iostream>
#include "MovieList.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"

int main() {

    MovieList list;

    std::cout << "=== STRESS TEST START ===\n";

    // ---------------- COMEDY STRESS ----------------
    list.add(new ComedyMovie("Blended", "Adam Sandler", 2016, 10));
    list.add(new ComedyMovie("Zoolander", "Ben Stiller", 2001, 10));
    list.add(new ComedyMovie("Blended", "Adam Sandler", 2014, 5));

    // ---------------- DRAMA STRESS ----------------
    list.add(new DramaMovie("Jaws", "Steven Spielberg", 1975, 8));
    list.add(new DramaMovie("A.I.", "Steven Spielberg", 2001, 6));
    list.add(new DramaMovie("Jaws", "Steven Spielberg", 1975, 2));

    // ---------------- CLASSIC STRESS ----------------
    list.add(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Katherine Hepburn"));
    list.add(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Cary Grant"));
    list.add(new ClassicMovie("Holiday", "George Cukor", 9, 1938, 10, "Another Actor"));

    list.add(new ClassicMovie("Casablanca", "Michael Curtiz", 8, 1942, 10, "Humphrey Bogart"));
    list.add(new ClassicMovie("Casablanca", "Michael Curtiz", 8, 1942, 10, "Ingrid Bergman"));

    std::cout << "\n=== DISPLAY INVENTORY ===\n";
    list.display();

    std::cout << "\n=== STRESS TEST END ===\n";

    return 0;
}