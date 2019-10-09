#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main()
{
    std::string s{"foo"};
    std::cout << "Welcome to the " << s << " program!\n";
    std::cout << "Enter two floating point numbers followed by [RETURN]\n";

    double d1{};
    double d2{};
    std::cin >> d1 >> d2;

    std::cout << "The sum is: " << d1 + d2 << '\n';

    std::cout << "Enter one floating point number\n";
    double d3{};
    std::cin >> d3;

    std::cout << "Abgerundet: " << floor(d3) << '\n';
    std::cout << "Aufgerundet: " << ceil(d3) << '\n';
    std::cout << "Wurzel: " << sqrt(d3) << '\n';
    std::cout << "Mehr Nachkommastellen " << std::fixed << std::setprecision(8) << sqrt(d3) << '\n';
    std::cout << "Weniger Nachkommastellen " << std::fixed << std::setprecision(2) << sqrt(d3) << '\n';
    std::cout << "Zur Basis von e " << std::scientific << sqrt(d3) << '\n';
}