#include <iostream>

using namespace std;

void sayHi(string name, int age){
    cout << "Hello User " << name << endl;
    cout << "You are " << age << endl;
}

double cube(double num);

// avoid to copy values by passing referenced parameters, make them const to avoid changing them.
void print(string const & str)  // copy integers saves more space, than referencing them
{
    cout << str << '\n';
}

/* function overloading */

double square(double const d)
{
    return d * d;
}

uint32_t square(uint32_t const i)
{
    return i * i;
}

/* function templates */
template <typename T>
T square(T const n)
{
    return n * n;
}

template <typename T1, typename T2>
auto add(T1 const n1, T2 const n2)
{
    return n1 * n2;
}

// in C++20:
// auto add(auto const n1, auto const n2)
// {
//     return n1 * n2;
// }

int main() {

    string name = "Ira";
    int age = 77;
    sayHi(name, age);

    double answer = cube(5.0);
    cout << answer;

    string s{"test"};
    print(s);

    uint32_t i = 7;
    std::cout << square(i) << '\n';     // compiler pics the second function

    uint8_t i8 = 4;
    std::cout << square(i8) << '\n';    // the template builds the square function

    int ii = 4;
    double d = 3;
    std::cout << add(ii, d) << '\n';
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
