#include <iostream>
#include <cmath>

using namespace std;

void sayHi(string name, int age){
    cout << "Hello User " << name << endl;
    cout << "You are " << age << endl;
}

double cube(double num);

int main() {

    int luckyNums[20] = {4, 8, 15, 16, 23, 42};
    luckyNums[10] = 100;
    cout << luckyNums[10] << endl;
    cout << luckyNums[11] << endl;

    string name = "Ira";
    int age = 77;
    sayHi(name, age);

    double answer = cube(5.0);
    cout << answer;

    /* std arrays: */
    array<double, 3> dd;    // use std arrays instead of build in arrays
    array<double, 3> df{3.1,4.5,3.5};

    /* std vectors: */
    vector<double> dd;      // resizable arrays
    vector<double, 3> df{3.1,4.5,3.5};
    df.size();
    df.end();

    /* std string: */
    string dd;              // similar to vector<char> (but a string you can print in a whole)
}

// Functions must be declared before being called:
void uselessFunction(){}

// But this works:
double cube(double num) {
    double result = num * num * num;
    return result;
    // Any code after a return keyword will not be output because the function has already been exited.
    cout << "This will never get printed";
}
