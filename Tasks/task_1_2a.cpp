#include <iostream>
// #include <string>

// #include <cstdio>
// #include <cinttypes>

//ToDo: std::uint8_t foobar() {
int foobar() {
    int const a = 3;
    return a;
}

int foobar2() {
    int a = 5;
    return a;
}

const double* square(double const d) {
    double const prod = d * d;
    return & prod;
}

void print(std::string const & str) {
    std::cout << str << '\n';
}



int main() {

    std::cout << "uint8_t is of type: \t" << typeid(uint8_t).name() << " with the size of \t" << sizeof(uint8_t)*8
        << " bits, and values go from " << 0 << " to " << UINT8_MAX << ".\n";

    int b = foobar();       // b gets no const type from foobar()
    std::cout << b << '\n';
    b = 2;
    std::cout << b << '\n';

    int const c = foobar2();    // c can be initialized with a non const value of a function, but is still const.
    std::cout << c << '\n';
    // c = 2;

/*
What happens when you return a reference? What about the example
on slide 20?
What combinations of const, const &, & (and none) are there for variables
and for function return values? Which combinations are valid/invalid
for initialising the variable?
*/
    double de = square(3.4);
    std::cout << de << '\n';

    std::string s{"test"};
    print(s);
}