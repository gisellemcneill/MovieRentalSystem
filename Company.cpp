#include "Company.h"

Company::Company() {}
Company::~Company() {}

void Company::loadMovies(string& fileName) {
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
void Company::loadCustomers(string& fileName) {
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
void Company::processCommands(string& fileName) {
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
                cout << customer;
                continue;
            }

            case 'B': {
                int ID;
                string mType;
                ss >> ID >> mType;

                Customer* customer = customers.getCustomer(ID);
                Transaction* t;

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
                        t = bFac.createTransaction(newMovie, ID);
                    }
                }
                t->execute(*this);
                customer->addTransaction(t);
                continue;
            }

            case 'R': {
                int ID;
                string mType;
                ss >> ID >> mType;

                Customer* customer = customers.getCustomer(ID);
                Transaction* t;

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
                        t = rFac.createTransaction(newMovie, ID);
                    }
                }
                t->execute(*this);
                customer->addTransaction(t);
                continue;
            }

            default :
                cerr << "WARNING: Invalid action code " << command << "\n";
                continue;
        }
    }
}