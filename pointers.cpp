#include <iostream>
#include <cstring>

using namespace std;

#define LOG(x) cout << x << endl

// Pointers are memory addresses
/*
* Pointers are simply a variable that hold an address so one could argue that a pointer is a data type, but it is not
* defined as a data type (per "The C Programming Language". Kernighan & Ritchie).
*/

int main() {
    /*
    * Variables are stored in the Memory of the Computer (RAM).
    * Each value is stored in a Container in the Memory, which has an address.
    * When the Computer wants to access the Value, it needs the Memory address.
    * In C++ we call these addresses pointers.
    */
    int age = 19;
    double gpa =2.7;
    string name = "Mike";

    // We can print out this address/pointer, when we use the ampersand (&):

    cout << "Age: " << &age << endl;   // -> something like: 0x61fea4
    cout << "Gpa: " << &gpa << endl;
    cout << "Name: " << &name << endl;

    // If we want to save the pointer in a variable, we use the asterisk (*) and create it based of our variable:

    int *pAge = &age;
    double *pGpa = &gpa;
    string *pName = &name;

    // Without the asterisk (*), we get the pointer:

    cout << "Our Addresses are: " << pAge << ", " << pGpa << " and "  << pName << endl;

    // Dereference a pointer:

    cout << "Inside of the Addresses we have: " << *pAge << ", " << *pGpa << " and "  << *pName << endl;
    cout << "\e[1m*&age\e[0m ist the same as \e[1m*pAge\e[0m  and \e[1mage\e[0m: "
        << *pAge << " = " << *&age << " = " << age << endl;
    cout << "But \e[1m&*&age\e[0m ist the same as \e[1mpAge\e[0m and \e[1m&age\e[0m: "
        << &*&age << " = " << pAge << " = " << &age << endl;

    // --------------------------------------------------------------------------------------

    void* emptyPtr = nullptr;      // Empty pointer (same as void* ptr = 0 or NULL;)

    int var = 8;                // int is 4 bytes
    int* ptr = &var;            // same as void* ptr = &var;     ptr adresses to the 4 bytes

    cout << "Our var=" << var << " is at the memory position: " << ptr << endl;

    *ptr = 10;                  // is only possible if *ptr is not void, because otherwise we dont know in how many bytes we're saving the new data.

    cout << "Our var=" << var << " is at the memory position: " << ptr << endl;

    char* buffer = new char[8]; // chars are 1 byte big
    memset(buffer, 0, 8);        // memset fills a block of memory with the data which we specify

    cout << "Our buffer=" << buffer;
    // for (int i : buffer) cout << i; // should give 000000000
    cout << " is at the memory position: " << &buffer << endl;

    delete[] buffer;            // delete the allocated memory afterwards;

    char** secPtr = &buffer;       // pointer to a pointer

    cout << "Our buffer=" << buffer << " is at the memory position: " << secPtr << endl;

}