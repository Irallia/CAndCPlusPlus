#include <iostream>
// #include <functional>
// #include <vector>
// #include <algorithm>

using namespace std;

int main() {

    /* Examples: */
    auto sayHelloWorld = []() {             // You can define a lambda function in the main method
        cout << "no" << endl;               // and it is a function without a name.
    };
    sayHelloWorld();

    auto product = [](int x, int y) -> int { // giving the return type (-> int) is optional
        return x * y;
    };
    cout << "Product is: " << product(7, 10) << endl;

    /* ...out of scope... */
    int i = 10;
    int j = 4;
    int g = 5;
    auto randomProduct = [j, &g](int a, int b) -> int {
        // return i;                        // You can't access i here!
        int product = j * g;                // But you can access j and g, because its captured in the capture list.
        // j = 0;                           // On the other hand, you can't change j, because it is read only.
        g = a * b;                          // If you pass a variable by referencing it (&), you are free to change it.
        return product * g;
    };
    cout << "Product is: " << randomProduct(7, 10) << endl;

    /* syntactic sugar: */
    auto otherProduct = [=](int a, int b) -> int {
        return i * j * g * a * b;           // The "=" adds all variables automaticaly to the capture list.
    };
    cout << "Product is: " << otherProduct(7, 10) << endl;

    auto nextProduct = [&, i](int a, int b) -> int {
        j = 60;                             // The "&" adds all variables automaticaly to the capture list by reference.
        // i = 4;                           // Exclude i by adding it extra ([=, &j] would be the other way around).
        return i * j * g * a * b;
    };
    cout << "Product is: " << nextProduct(7, 10) << endl;

    return 0;
}