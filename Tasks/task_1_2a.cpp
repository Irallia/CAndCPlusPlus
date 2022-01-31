#include <iostream>

/*
 * What happens when you return something of const type from a function? Can constants be initialised from functions
 * that return a non-const type?
 * What happens when you return a reference?
 * What combinations of const, const &, & (and none) are there for variables and for function return values? Which
 * combinations are valid/invalid for initialising the variable?
 *
 * int a            = (1), (2), (3), (4)
 * int & a          = (2)
 * int const a      = (1), (2), (3), (4)
 * int const & a    = (2), (4)
 *
 * (1) int f()
 * (2) int & f()
 * (3) int const f()
 * (4) int const & f()
 *
 * */

// bool just_value() {
//     return true;
// }

// bool const just_value() {
//     return true;
// }

// bool just_value() {
//     bool
// }

// bool just_value() {

// }

// // value const =
// {
//     [[maybe_unused]]
//     bool const
// }



//ToDo: std::uint8_t foobar() {
int foobar() {
    int const a = 3;
    return a;
}

int foobar2() {
    int a = 5;
    return a;
}

constexpr double* square(double const d) {
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

    const double* de = square(3.4);
    std::cout << de << '\n';

    std::string s{"test"};
    print(s);
}
