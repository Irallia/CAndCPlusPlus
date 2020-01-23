#include <iostream>
#include <vector>
#include <tuple>

int main() {


    /* type deduction: (since C++17) */
    // std::vector v{3.3, 5.6};    // deduced to std::vector<double>
    // std::tuple t{4, 4.5};       // deduced to std::tuple<int, double>

    // std::pair p(2, 4.5);     // deduces to std::pair<int, double> p(2, 4.5);
    // std::less l;             // same as std::less<void> l;

    std::tuple<std::string, std::string> cosmonaut{"Sigmund", "Jaehn"};
    auto & [f, l] = cosmonaut;
    std::cout << f << ' ' << l << '\n';
}
