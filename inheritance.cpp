#include <iostream>
using namespace std;

class Chef {
    public:
        void makeChicken(){
            cout << "The Chef makes chicken." << endl;
        }
        void makeSalad(){
            cout << "The Chef makes Salad." << endl;
        }
};

// inheritance = Erbe
// We want to inherit the functions from the Chef class into the special ItalianChef class
class ItalianChef : public Chef {
    public:
        //overriding functions:
        void makeChicken(){
            cout << "The Chef makes italian chicken." << endl;
        }
        //add more functions:
        void makePasta(){
            cout << "The Chef makes pasta." << endl;
        }
};

int main() {
    Chef chef;
    chef.makeChicken();

    ItalianChef italianChef;
    italianChef.makeChicken();
    italianChef.makePasta();
    // but chef.makePasta() doesn't work.

    return 0;
}