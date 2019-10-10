#include <iostream>
#include <vector>
#include <tuple>

int main() {
    /* type deduction: */
    std::vector v{3.3, 5.6};    // deduced to std::vector<double>
    std::tuple t{4, 4.5};       // deduced to std::tuple<int, double>

    std::tuple<std::string, std::string> cosmonaut{"Sigmund", "Jaehn"};
    auto & [f, l] = cosmonaut;
    std::cout << f << ' ' << l << '\n';
}
