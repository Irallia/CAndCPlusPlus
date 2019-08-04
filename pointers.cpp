#include <iostream>
#include <cstring>

using namespace std;

#define LOG(x) cout << x << endl

int main()
{
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

    cin.get();

}