#include <stdio.h>
#include <stdlib.h>

// Disable error squiggles and introduce std::strcpy() to use it in C++:
#include <cstring>
using namespace std;

/*
* In what scenarios is it better to use a struct vs a class in C++?
*
* Differences between a class and a struct in C++ are that structs have default public members and bases and classes
* have default private members and bases. Both classes and structs can have a mixture of public, protected and private
* members, can use inheritance and can have member functions.
* I would recommend using structs as plain-old-data structures without any class-like features, and using classes as
* aggregate data structures with private data and member functions.
*
* https://stackoverflow.com/questions/54585/when-should-you-use-a-class-vs-a-struct-in-c
*/

struct Student{
    char name[50];
    char major[40];
    int age;
    double gpa;
};

int main() {
    struct Student student1;
    student1.age = 22;
    student1.gpa = 2.3;
    // student1.name = "Jim";       // Thats not gonna work, because its an array.
    strcpy(student1.name, "Jim");   // In C++ you should use the type string instead,
    strcpy(student1.major, "Math"); // strcpy is a potential security risk, because it does not check array boundaries.

    printf("%s", student1.name);

    return 0;
}