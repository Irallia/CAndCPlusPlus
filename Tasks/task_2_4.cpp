#include "task_2_4-header.hpp"

// ToDo:
// Why can templates not have their definitions in separate cpp files? Think about / find out!

int main()
{
    Complex<double> c1{1, 1};
    Complex<double> c2{2, 3};
    Complex<double> c3 = c1 + c2;
    c3.print();
    c3 = c1 - c2;
    c3.print();
    c3 = c1 * c2;
    c3.print();
    c3 = c1 / c2;
    c3.print();

    Complex<double> c4{4, 5};
    c4 += c1;
    c4.print();
    c4 -= c1;
    c4.print();
    c4 *= c2;
    c4.print();
    c4 /= c2;
    c4.print();

    if (c1 == c2)
        std::cout << "true!\n";
    else
        std::cout << "false!\n";

    if (c1 != c2)
        std::cout << "true!\n";
    else
        std::cout << "false!\n";
}