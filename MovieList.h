// ------------------------------------------------ MovieList.h --------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/1/26

// Date of Last Modification: 6/5/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the MovieList class, which serves as the storage and retrieval system for all movies in the
// movie rental store inventory system. MovieList maintains sorted sets based on genre
// and custom comparators will be used to ensure correct sorting order depending on the genre

// Movies are sorted and stored as followed by genre:
// Comedy (F) -> sorted by title then releaseYear
// Drama (D) -> sorted by director then title
// Classic (C) -> sorted by releaseDate then majorActor

// MovieList allows adding movies, finding movies using genre sorting fields and
// displaying all movies in sorted order by genre

// Movie List owns Movie objects stored in the sets is need to delete them in the
// destructor to prevent memory leaks
// --------------------------------------------------------------------------------------------------------------------


#ifndef PROGRAM4_MOVIELIST_H
#define PROGRAM4_MOVIELIST_H

#include <set>
#include <string>
#include <vector>
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"

using namespace std;

class MovieList {
public:

    MovieList(); //constructor
    ~MovieList(); //destructor will delete all Movie objects

    void add(Movie* movie); //add a movie to genre-specific set

    //genre-specific find function
    ComedyMovie* findComedy(const string& title, int year) const;
    DramaMovie* findDrama(const string& director, const string& title) const;
    ClassicMovie* findClassic(int month, int year, const string& actor) const;

    //find all available classics with given title
    vector<ClassicMovie*> findClassicsByTitle(const string& title) const;


    void displayClassic() const; //formatting for ClassicMovie
    void display() const; //display all movies in sorted order by genre

private:

    set<ComedyMovie*, ComedyComparator> comedies; //set only holding ComedyMovies
    set<DramaMovie*, DramaComparator> dramas; //set only holding DramaMovie
    set<ClassicMovie*, ClassicComparator> classics; //set only holding ClassicMovies

};

#endif //PROGRAM4_MOVIELIST_H