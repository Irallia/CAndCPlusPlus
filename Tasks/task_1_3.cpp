#include <iostream>

template <typename T>
T fibonacci(T n1, T n2, int counter) {
    T newNumber = n2;
    while (counter - 2 > 0) {
        newNumber = n1 + n2;
        n1 = n2;
        n2 = newNumber;
        counter--;
    }
    return newNumber;
}

int main() {
    std::cout << "Please enter two floating point numbers.\n";

    float f1;
    float f2;

    std::cin >> f1 >> f2;
    std::cout << "The 42th fibonacci number of these initial numbers is: " << fibonacci(f1, f2, 42);

}
