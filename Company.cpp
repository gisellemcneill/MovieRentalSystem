#include "Company.h"

Company::Company() {}
Company::~Company() {}

void Company::loadMovies(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "ERROR: Could not load movies, file does not exist\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string tempGenre, tempStock, director, title;

        getline(ss, tempGenre, ',');
        getline(ss, tempStock, ',');
        getline(ss, director, ',');
        getline(ss, title, ',');

        char genre = tempGenre.find_first_not_of(" \t") != string::npos ? tempGenre[tempGenre.find_first_not_of(" \t")] : ' ';
        int stock = stoi(tempStock);
        if (!director.empty() && director[0] == ' ') director.erase(0, 1);
        if (!title.empty() && title[0] == ' ') title.erase(0, 1);

        if (genre != 'F' || genre != 'D' || genre != 'C') {
            Movie* newMovie = mFac.createMovie(genre, stock, director, title, ss);

            if (newMovie != nullptr) {
                inventory.addMovie(newMovie);
            }
        }
        else {
            cerr << "WARNING: Invalid movie genre " << genre << "\n";
        }
    }
}
void Company::loadCustomers(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "ERROR: Could not load customers, file does not exist\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        int ID;
        string lName, fName;

        ss >> ID >> lName >> fName;
        customers.addCustomer(ID, lName, fName);
    }
}
void Company::processCommands(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "ERROR: Could not process commands, file does not exist\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        char command;
        ss >> command;

        switch (command) {

            case 'I' :
                inventory.displayInventory();
                continue;

            case 'H': {
                int ID;
                ss >> ID;

                Customer* customer = customers.getCustomer(ID);

                //Added a check for invalid ID
                if (customer == nullptr) {
                    cerr << "ERROR: Invalid Customer ID  " << ID << endl;
                    continue;
                }

                customer -> displayHistory(cout);
                continue;
            }

            case 'B':
            case 'R': {
                int ID;
                char mType;
                char genre; //added this to grab genre
                ss >> ID >> mType >> genre; //ss will now read genre

                //need to validate mediaType
                if (mType != 'D') {
                    cerr << "ERROR: Invalid media type " << mType <<endl;
                    continue;
                }

                Customer* customer = customers.getCustomer(ID);
                //Added customer validation
                if (customer == nullptr) {
                    cerr << "ERROR: Invalid Customer ID  " << ID << endl;
                    continue;
                }

                Movie* newMovie = nullptr; //create new movie

                //if checks for which genre
                if (genre == 'F') {
                    string title;
                    int year;
                    getline(ss, title, ','); //parsing logic now that comma exist
                    ss >> year;

                    //Remove the leading space on command line for title
                    if (!title.empty() && title[0] == ' ') {
                        title.erase(0, 1);
                    }

                    //search inventory for real movie
                    ComedyMovie* real = inventory.findComedy(title, year);
                    //validate that real is a Movie
                    if (real == nullptr) {
                        cerr << "ERROR: ComedyMovie not found in inventory" << endl;
                        continue;
                    }
                    newMovie = real -> clone();

                }else if (genre == 'D') {
                    string director, title;
                    getline(ss, director, ',');
                    getline(ss, title, ',');

                    //remove leading spaces
                    if (!director.empty() && director[0] == ' ') {
                        director.erase(0, 1);
                    }

                    if (!title.empty() && title[0] == ' ') {
                        title.erase(0, 1);
                    }

                    //search inventory for real movie
                    DramaMovie* real = inventory.findDrama(director, title);
                    //validate that real is a Movie
                    if (real == nullptr) {
                        cerr << "ERROR: ComedyMovie not found in inventory" << endl;
                        continue;
                    }
                    newMovie = real -> clone();

                }else if (genre == 'C') {
                    int month, year;
                    string firstName, lastName;
                    ss >> month >> year >> firstName >> lastName;
                    string actor = firstName + " " + lastName;

                    //find the real movie
                    ClassicMovie* real = inventory.findClassic(month, year, actor);
                    if (real == nullptr) {
                        cerr << "ERROR: ClassicMovie not found" << endl;
                        continue;
                    }
                    //create a new movie
                    newMovie = real -> clone();

                }else {
                    cerr << "ERROR: Invalid genre " << genre << endl;
                    continue;
                }


                if (newMovie == nullptr) {
                    cerr << "ERROR: New Movie not found in inventory" << endl;
                    continue;
                }

                //Create the transaction
                Transaction* t = nullptr;
                if(command == 'B') {
                    t = bFac.createTransaction(newMovie, ID);
                }else { //Case R
                    t = rFac.createTransaction(newMovie, ID);
                }

                //Check if t exists
                if (t == nullptr) {
                    cerr << "ERROR: Could not create Transaction" << endl;
                    delete newMovie;
                    continue;
                }

                bool success = t -> execute(*this);
                if (success) {
                    customer -> addTransaction(t);
                }else {
                    delete t;
                }
                continue;
            }

            default :
                cerr << "ERROR: Invalid command " << command << endl;
                continue;

        }
    }
}