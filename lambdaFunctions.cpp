#include <iostream>
#include <vector>
#include <cmath>

template <typename TElem>
void square_all_elements(std::vector<TElem> & vec)
{
    for (TElem & elem : vec)
    elem = elem * elem;
}

template <typename TElem>
void squareroot_all_elements(std::vector<TElem> & vec)
{
    for (TElem & elem : vec)
    elem = std::sqrt(elem);
}


template <typename TElem, typename TLambda>
void on_all_elements(std::vector<TElem> & vec, TLambda const & l)
{
    for (TElem & elem : vec)
        elem = l(elem);
}

int main() {

    auto square      = [] (auto const & elem) { return elem * elem; };
    auto square_root = [] (auto const & elem) { return std::sqrt(elem); };
    // Each lambda has a distinct type -> you have to use auto.
    std::vector<double> ds{0.2, 1.5, 2};
    on_all_elements(ds, square);        // ds == { 0.04, 2.25, 4 }
    on_all_elements(ds, square_root);   // ds == { 0.20, 1.50, 2 }

    [](){}; // minimalistic lambda expression
            // [] introduce the lambda expression
            // () contains the parameters
            // {} conrains the body of the lambda function



    // /* Examples: */
    // auto sayHelloWorld = []() {             // You can define a lambda function in the main method
    //     std::cout << "no" << '\n';               // and it is a function without a name.
    // };
    // sayHelloWorld();

    // auto product = [](int x, int y) -> int { // giving the return type (-> int) is optional
    //     return x * y;
    // };
    // std::cout << "Product is: " << product(7, 10) << '\n';

    // /* ...out of scope... */
    // int i = 10;
    // int j = 4;
    // int g = 5;
    // auto randomProduct = [j, &g](int a, int b) -> int {
    //     // return i;                        // You can't access i here!
    //     int product = j * g;                // But you can access j and g, because its captured in the capture list.
    //     // j = 0;                           // On the other hand, you can't change j, because it is read only.
    //     g = a * b;                          // If you pass a variable by referencing it (&), you are free to change it.
    //     return product * g;
    // };
    // std::cout << "Product is: " << randomProduct(7, 10) << '\n';

    // /* syntactic sugar: */
    // auto otherProduct = [=](int a, int b) -> int {
    //     return i * j * g * a * b;           // The "=" adds all variables automaticaly to the capture list.
    // };
    // std::cout << "Product is: " << otherProduct(7, 10) << '\n';

    // auto nextProduct = [&, i](int a, int b) -> int {
    //     j = 60;                             // The "&" adds all variables automaticaly to the capture list by reference.
    //     // i = 4;                           // Exclude i by adding it extra ([=, &j] would be the other way around).
    //     return i * j * g * a * b;
    // };
    // std::cout << "Product is: " << nextProduct(7, 10) << '\n';

}