#include <iostream>
#include <vector>

/* Recommendations
 * 1. By default make all function parameters const &
 * 2. Ask yourself: do I want to change it?
 * 1. no
 * 1. arithmetic type? → just const
 * 2. else → keep const &
 * 2. yes
 * 1. so that change is visible outside? → just &
 * 2. change only inside function? → neither const nor & (copy)
 * */

int main() {

    size_t i = 145;
    size_t j = i;               // i == 145
    std::cout << j << '\n';

    std::string s{"A text much longer than this example"};
    std::string t{s};           // t == "A text ..."

    std::string & t1{s};        // reference t to s

    std::cout << t1 << '\n';    // prints "A text ..."
    t = "a shorter text";

    std::cout << s << '\n';     // prints "s shorter text"

    // -> t is just another name of s

    std::string const & t2{s};  // We can't change t2, because it is const, but we can still change s.

    std::string s1{"A text much longer than this example"};
    // std::string & t3{s1};
    std::string const & t3{s1};

    std::cout << "t2, t3: "<< t2 << ' ' << t3 << '\n';

    std::vector<std::string> chromosomes{"c1", "c2", "c3", "c4"};
    // iterate over the chromosomes WITHOUT copying on each iteration
    for (std::string const & chromosome : chromosomes)
    {
        std::cout << "length: " << chromosome.size() << '\n';
    }

    std::vector<size_t> vec{1, 2, 3};
    for (size_t i : vec)    // vec is unchanged
    {
        i = i * i;
    }

    for (size_t & i : vec)  // vec is { 1, 4, 9}}
    {
        i = i * i;
    }

}