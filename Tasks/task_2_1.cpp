#include <iostream>
#include <vector>

// It should return a vector with those elements of the input for which the lambda function evaluates to true.
template <typename TLambda>
std::vector<size_t> filter(std::vector<size_t> const & input, TLambda const & l)
{
    std::vector<size_t> output{};
    for (size_t const & elem : input)
        if (l(elem))
            output.push_back(elem);
    return output;
}

int main() {

    auto isEven     = [] (auto const & elem) { return (elem % 2 == 0); };
    auto isOdd      = [] (auto const & elem) { return (elem % 2 != 0); };
    auto isNotZero  = [] (auto const & elem) { return (elem != 0); };

    std::vector<size_t> v{2, 5, 3, 8, 0, 1, 5, 0, 7};
    std::vector<size_t> v1 = filter(v, isEven);     // v == {2, 8, 0, 0}
    std::vector<size_t> v2 = filter(v, isOdd);      // v == {5, 3, 1, 5, 7}
    std::vector<size_t> v3 = filter(v, isNotZero);  // v == {2, 5, 3, 8, 1, 5, 7}

    std::cout << v1.size() << ", " << v2.size() << ", " << v3.size() << '\n';

}