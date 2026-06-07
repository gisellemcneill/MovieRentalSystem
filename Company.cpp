// ------------------------------------------------ Company.cpp -------------------------------------------------------

// Giselle McNeill, Nash Kumia CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date: 6/05/26

// Date of Last Modification: 6/6/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Implements the Company class, which parses, formats, and directs input for the program and produces output. 

// Implements Company member functions including:
// Company(), ~Company(), loadMovies(), loadCustomers(), processCommands(), findCustomer(), getInventory()
// --------------------------------------------------------------------------------------------------------------------

#include "Company.h"
#include "Transaction.h"
// ------------------------------------ Company Constructor ------------------------------------
// Description:
// Initializes an empty Company.
//
// Preconditions:
// None
//
// Postconditions:
// Company is initialized with an empty Inventory, CustomerData, and all object factories
// --------------------------------------------------------------------------------------------
Company::Company() {}
//End of Company Constructor


// ------------------------------------ Company Destructor ------------------------------------
// Description:
// Destroys the Company object. Inventory and CustomerData destructors are automatically
// called and handles deletion of all stored Movie, Customer, and Transaction objects.
//
// Preconditions:
// None
//
// Postconditions:
// All Movie objects are deleted via the Inventory
// All Customer objects are deleted via CustomerData
// All Transaction object are deleted via Customer
// --------------------------------------------------------------------------------------------
Company::~Company() {}
// End of ~Company()

// ------------------------------------ loadMovies() ------------------------------------
// Description:
// Reads and processes all movies from the given movies file line by line.
// Supports three genres: F (comedy), D (drama), C (classic).
// Invalid genres are caught and reported with error messages, then discarded
// and processing continues with the next line.
//
// Preconditions:
// fileName is a valid path to a readable movie file.
// file is properly formatted
//
// Postconditions:
// All valid movies are created and stored in the inventory.
// --------------------------------------------------------------------------------------------
bool Company::loadMovies(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cout << "ERROR: Could not load movies, file \"" << fileName << "\" does not exist" << "\n" << flush;
        return false;
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

        if (genre == 'F' || genre == 'D' || genre == 'C') {
            if (stock >= 0) {
                Movie* newMovie = mFac.createMovie(genre, stock, director, title, ss);

                if (newMovie != nullptr) {
                    inventory.addMovie(newMovie);
                }
            }
            else {
                cout << "ERROR: Invalid stock amount " << stock << "\n" << flush;
            }
        }
        else {
            cout << "ERROR: Invalid movie genre " << genre << "\n" << flush;
        }
    }
    cout << "Finished loading file \"" << fileName << "\"" << "\n" << flush;
    return true;
}
//End of loadMovies()


// ------------------------------------ loadCustomers() ------------------------------------
// Description:
// Reads and processes all customers from the given customers file line by line.
// Rejects repeat customer IDs.
//
// Preconditions:
// fileName is a valid path to a readable customer file.
// file is properly formatted with 4-digit customer IDs followed by firstName lastName.
//
// Postconditions:
// All valid customers are created and stored in CustomerData
// --------------------------------------------------------------------------------------------
bool Company::loadCustomers(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cout << "ERROR: Could not load customers, file \"" << fileName << "\" does not exist" << "\n" << flush;;
        return false;
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
    cout << "Finished loading file \"" << fileName << "\"" << "\n" << flush;
    return true;
}
//End of loadCustomers()


// ------------------------------------ processCommands() ------------------------------------
// Description:
// Reads and processes all commands from the given command file line by line.
// Supports four action codes: I (inventory), H (history), B (borrow), R (return).
// For B and R commands parses genre specific fields and finds the corresponding
// movie in inventory before creating and executing the transaction.
// Invalid action codes, media types, genres, customer IDs, and movie lookups
// are caught and reported with error messages. Invalid commands are discarded
// and processing continues with the next line.
//
// Preconditions:
// fileName is a valid path to a readable command file
// Inventory and CustomerData are already loaded
//
// Postconditions:
// All valid commands are executed and applied to inventory and customer history
// All invalid commands are discarded with appropriate error messages printed
// --------------------------------------------------------------------------------------------
bool Company::processCommands(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cout << "ERROR: Could not process commands, file \"" << fileName << "\" does not exist" << "\n" << flush;
        return false;
    }

    cout << "\n---------- Processing commands from \"" << fileName << "\" --------\n\n";

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        char command;
        ss >> command;

        switch (command) {

            case 'I' :
                cout << "\n-------------------- INVENTORY --------------------\n\n";
                inventory.displayInventory();
                continue;

            case 'H': {
                int ID;
                ss >> ID;

                Customer* customer = customers.getCustomer(ID);

                //Added a check for invalid ID
                if (customer == nullptr) {
                    cout << "ERROR: Customer ID  " << ID << " not found\n" << flush;
                    continue;
                }

                cout << "\n---------- History for customer " << ID << ": " << "--------\n\n";

                customer -> displayHistory(cout);

                cout << "---------- End of History ----------\n";

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
                    cout << "ERROR: Invalid media type " << mType << "\n" << flush;
                    continue;
                }

                Customer* customer = customers.getCustomer(ID);
                //Added customer validation
                if (customer == nullptr) {
                    cout << "ERROR: Customer ID  " << ID << " not found\n" << flush;
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
                        cout << "ERROR: " << title << " not found in inventory" << "\n" << flush;
                        continue;
                    }
                    newMovie = real -> clone();

                } else if (genre == 'D') {
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
                        cout << "ERROR: " << title << " not found in inventory" << "\n" << flush;
                        continue;
                    }
                    newMovie = real -> clone();

                } else if (genre == 'C') {
                    int month, year;
                    string firstName, lastName;
                    ss >> month >> year >> firstName >> lastName;
                    string actor = firstName + " " + lastName;

                    //find the real movie
                    ClassicMovie* real = inventory.findClassic(month, year, actor);
                    if (real == nullptr) {
                        cout << "ERROR: Classic movie not found in inventory" << "\n" << flush;
                        continue;
                    }
                    //create a new movie
                    newMovie = real -> clone();

                }else {
                    cout << "ERROR: Invalid genre " << genre << "\n" << flush;
                    continue;
                }


                if (newMovie == nullptr) {
                    cout << "ERROR: New Movie not found in inventory" << "\n" << flush;
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
                    cout << "ERROR: Could not create Transaction" << "\n" << flush;
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
                cout << "ERROR: Invalid command " << command << "\n" << flush;
                continue;

        }
    }
    cout << "Finished processing file \"" << fileName << "\"" << "\n\n" << flush;
    return true;
}


// ------------------------------------ findCustomer() ------------------------------------
// Description:
// Searches the CustomerData hash table for a Customer with the given ID.
// Delegates entirely to CustomerData::getCustomer().
//
// Preconditions:
// id is a valid 4 digit integer
//
// Postconditions:
// Returns pointer to matching Customer if found
// Returns nullptr if customer ID not found
// CustomerData is unchanged
// --------------------------------------------------------------------------------------------
Customer* Company::findCustomer(int id) {

    return customers.getCustomer(id);

}
//End of findCustomer()


// ------------------------------------ getInventory() ------------------------------------
// Description:
// Returns a reference to the Inventory object owned by Company.
// Used by Transaction subclasses to access and modify movie stock
// during borrow and return operations.
//
// Preconditions:
// None
//
// Postconditions:
// Returns reference to Inventory object
// Company and Inventory are unchanged
// --------------------------------------------------------------------------------------------
Inventory& Company::getInventory() {

    return inventory;

}
//End of getInventory()
