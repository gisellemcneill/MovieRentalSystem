#include <iostream>
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"

using namespace std;

int main() {

    cout << "==============================\n";
    cout << "       COMEDY TESTS\n";
    cout << "==============================\n";

    ComedyMovie c1("Blended", "Adam Sandler", 2016, 10);
    ComedyMovie c2("Blended", "Adam Sandler", 2017, 10);
    ComedyMovie c3("Waterboy", "Adam Sandler", 2005, 2);

    cout << "--- DISPLAY ---\n";
    cout << c1 << endl;
    cout << c2 << endl;

    cout << "--- OPERATOR < ---\n";
    cout << (c1 < c2) << " (check title/year rule)" << endl;
    cout << (c2 < c1) << endl;

    cout << "--- EQUALITY ---\n";
    ComedyMovie c4("Waterboy", "Different Director", 2005, 5);
    cout << (c3 == c4) << " (expect 1)" << endl;

    cout << "--- STOCK ---\n";
    cout << c3.getStock() << endl;
    cout << c3.decrementStock() << endl;
    cout << c3.getStock() << endl;
    cout << c3.decrementStock() << endl;
    cout << c3.getStock() << endl;
    cout << c3.decrementStock() << " (expect 0/false after empty)" << endl;


    cout << "\n==============================\n";
    cout << "        DRAMA TESTS\n";
    cout << "==============================\n";

    DramaMovie d1("Schindler's List", "Steven Spielberg", 1993, 10);
    DramaMovie d2("Jaws", "Steven Spielberg", 1975, 8);
    DramaMovie d3("Schindler's List", "Steven Spielberg", 1993, 5);

    cout << "--- DISPLAY ---\n";
    cout << d1 << endl;
    cout << d2 << endl;

    cout << "--- OPERATOR < ---\n";
    cout << (d2 < d1) << " (director/title rule)" << endl;

    cout << "--- EQUALITY ---\n";
    cout << (d1 == d3) << " (expect 1)" << endl;


    cout << "\n==============================\n";
    cout << "       CLASSIC TESTS\n";
    cout << "==============================\n";

    ClassicMovie a("Holiday", "George Cukor", 9, 1938, 10, "Katherine Hepburn");
    ClassicMovie b("Holiday", "George Cukor", 9, 1938, 10, "Cary Grant");
    ClassicMovie c("Holiday", "George Cukor", 10, 1938, 10, "Katherine Hepburn");
    ClassicMovie d("Holiday", "George Cukor", 9, 1938, 5, "Katherine Hepburn");

    cout << "--- DISPLAY ---\n";
    cout << a << endl;
    cout << "Display Actor: " << a.getMajorActor() << endl;
    cout << b << endl;
    cout << "Display Actor: " << b.getMajorActor() << endl;

    cout << "--- OPERATOR < ---\n";
    cout << (a < b) << " (month/year/actor rule)" << endl;

    cout << "--- EQUALITY ---\n";
    cout << "Compare same Movie, same Actor:" <<  (a == d) << " (expect 1)" << endl;
    cout << "Compare same Movie, different actor:" <<  (a == b) << " (expect 0)" << endl;

    cout << "\n==============================\n";
    cout << "        DONE\n";
    cout << "==============================\n";

    cout << "\n--- STOCK INDEPENDENCE ---\n";

    ClassicMovie e("Holiday", "George Cukor", 9, 1938, 2, "Katherine Hepburn");
    ClassicMovie f("Holiday", "George Cukor", 9, 1938, 2, "Cary Grant");

    cout << "Hepburn stock: " << e.getStock() << endl;
    cout << "Grant stock: " << f.getStock() << endl;

    a.decrementStock();

    cout << "After decrement Hepburn:\n";
    cout << "Hepburn stock: " << e.getStock() << endl;
    cout << "Grant stock (should NOT change): " << f.getStock() << endl;

    cout << "\n--- STOCK EXHAUSTION ---\n";

    ClassicMovie g("Holiday", "George Cukor", 9, 1938, 1, "Katherine Hepburn");

    cout<< " Expecting 1: " << endl;
    cout << g.decrementStock() << endl; // 1 → 0 (true)
    cout << " Expecting 0: " << endl;
    cout << g.decrementStock() << endl; // 0 → fail (false)

    cout << "\n--- EQUALITY DOES NOT DEPEND ON STOCK ---\n";

    ClassicMovie x("Holiday", "George Cukor", 9, 1938, 10, "Katherine Hepburn");
    ClassicMovie y("Holiday", "George Cukor", 9, 1938, 1, "Katherine Hepburn");

    cout<< " Expecting 1: " << endl;
    cout << (x == y) << endl; // should be 1

    return 0;
}