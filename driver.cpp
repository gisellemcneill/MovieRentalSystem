// ------------------------------------ Driver.cpp ------------------------------------
// Purpose:
// Runs the program and sends input to the Company class from cin. Allows the user to
// input and load any file and any number of files.
//
// --------------------------------------------------------------------------------------------

#include <iostream>
#include "Company.h"

using namespace std;

int main() {
    Company store;
    
    string in;
    bool cont = false;

    cout << "\n-------------------- Start of Program ------------------\n";
    //load movies
    while (!cont) {
        cout << "\nEnter movie file name: ";
        getline(std::cin, in);
        //if successful ask if done
        if (store.loadMovies(in)) {
            in = "";
            while (in.empty()) {
                cout << "\nLoaded all movies? [Y/N]: ";
                getline(std::cin, in);
                //parse Y/N
                if (in[0] == 'Y') {
                    cont = true;
                }
                else if (in[0] == 'N') {
                    cont = false;
                }
                else {
                    in = "";
                }
            }
        }
    }

    //load customers
    cont = false;
    while (!cont) {
        cout << "\nEnter customer file name: ";
        getline(std::cin, in);
        //if successful ask if done
        if (store.loadCustomers(in)) {
            in = "";
            while (in.empty()) {
                cout << "\nLoaded all customers? [Y/N]: ";
                getline(std::cin, in);
                //parse Y/N
                if (in[0] == 'Y') {
                    cont = true;
                }
                else if (in[0] == 'N') {
                    cont = false;
                }
                else {
                    in = "";
                }
            }
        }
    }

    //process input
    cont = false;
    while (!cont) {
        cout << "\nEnter command file name: ";
        getline(std::cin, in);
        if (store.processCommands(in)) {
            in = "";
            //if successful ask if done
            while (in.empty()) {
                cout << "\nProcessed all commands? [Y/N]: ";
                getline(std::cin, in);
                //parse Y/N
                if (in[0] == 'Y') {
                    cont = true;
                }
                else if (in[0] == 'N') {
                    cont = false;
                }
                else {
                    in = "";
                }
            }
        }
    }
    cout << "\n-------------------- End of Program ------------------\n";
    return 0;
}