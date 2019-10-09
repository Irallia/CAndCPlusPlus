#include <iostream>

template <typename T>
void print(T const i) {
    std::cout << i << " is an integer!\n";
}

void print(float const i) {
    std::cout << i << " is a floating point!\n";
}

void print(double const i) {
    std::cout << i << " is a floating point!\n";
}

int main() {
    print(3.3);
    std::cout << "With the type " << typeid(3.3).name() << ".\n";
    print(1e-10);
    std::cout << "With the type " << typeid(1e-10).name() << ".\n";

    float f = 3.6;
    print(f);
    std::cout << "With the type " << typeid(f).name() << ".\n";

    std::cout << "--------------------------------\n";

    std::cout << "char is of type: \t" << typeid(char).name() << "\n";
    std::cout << "short is of type: \t" << typeid(short).name() << "\n";
    std::cout << "int is of type: \t" << typeid(int).name() << "\n";
    std::cout << "long is of type: \t" << typeid(long).name() << "\n";
    std::cout << "long long is of type: \t" << typeid(long long).name()  << "\n";
    std::cout << "unsigned is of type: \t" << typeid(unsigned).name() << "\n";
    std::cout << "double is of type: \t" << typeid(double).name()  << "\n";
    std::cout << "float is of type: \t" << typeid(float).name() << "\n";

    std::cout << typeid(3.3).name();

}
