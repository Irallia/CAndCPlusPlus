#include <iostream>

template <typename T>
T fibonacci(T n1, T n2, int counter) {
    if (counter == 0)
        return n1;
    else
        return fibonacci(n2, n1 + n2, counter - 1);
}

int main() {
    std::cout << "Please enter two floating point numbers.\n";

    // ToDo: Wo ist der Unterschied???
    float f1{};
    float f2;

    std::cin >> f1 >> f2;
    std::cout << "The 42th fibonacci number of these initial numbers is: " << fibonacci(f1, f2, 42);

}
