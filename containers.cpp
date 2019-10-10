#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

/* Sequence containers:
 *
 *  std::array          Fast access, but fixed number of elements
 *  std::vector         Fast access, efficient insertion/deletion only at end
 *  std::basic_string   Like std::vector, but optimised for character types
 *  std::deque          Efficient insertion/deletion at beginning and end
 *  std::list           Efficient insertion/deletion also in the middle, no []
 *  std::forward_list   Efficient insertion/deletion also in the middle, no []
 *
 *  Using iterators:
 *      T my_cont{1, 2, 3, 4, 5};
 *      for (auto const & elem : my_cont)                            // "range-based"
 *          std::cout << elem << ' ';
 *      for (size_t i = 0; i < my_cont.size(); ++i)                  // via []
 *          std::cout << my_cont[i] << ' ';
 *      for (auto it = my_cont.begin(); it != my_cont.end(); ++it)   // via iterator
 *          std::cout << *it << ' ';
 *
 * Associative containers:
 *  std::set        std::unordered_set      collection of unique keys
 *  std::multiset   std::unordered_multiset collection of keys
 *  std::map        std::unordered_map      collection of key-value pairs; keys unique
 *  std::multimap   std::unordered_multimap collection of key-value pairs
 * */

int main() {

    /* build in arrays: */
    int luckyNums[20] = {4, 8, 15, 16, 23, 42};
    luckyNums[10] = 100;
    std::cout << luckyNums[10] << '\n';
    std::cout << luckyNums[11] << '\n';
    // use std arrays instead of build in arrays ->

    /* std::array */                        // size fixed at compile-time;
    std::array<double, 2> arr{3.1, 2.3};    // specified via second template argument.
    std::cout << arr[0]; // prints 3.1      // provides RandomAccessIterator
    arr[1] = 32.0;       // assigns value   // Use instead of built-in array in all serious projects,
    std::cout << arr.size() << ' ';         //      i.e. it has no drawbacks over built-in arrays.
    std::cout << arr.end() << '\n';

    /* std::vector */
    std::vector<uint16_t> vec{1, 22, 3, 44}; // "Dynamic" array (resizable).
    std::cout << vec[0]; // prints 3.1       // append values in O(1)
    vec[1] = 32.0;       // assigns value    // other inserts O(n)
    vec.push_back(2.2);  // append value     // fast access and no size overhead
    vec.resize(42);      // resize           // If you are unsure, probably the right choice of container.

    for(uint16_t e : vec)
        std::cout << e << ' ';

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << "elem no." << i << " is " << vec[i] << '\n';
    }

    /* std::basic_string */
    std::basic_string<char> str{"ABC"};     // Like std::vector<char>, only supports character types.
    //== std::string                        // Slightly slower access.
    std::cout << str[0]; // prints 'A'      // Optimizations for small strings.
    str[1] = 32.0; // assigns value         // Convenience functions for input/output.

    /* std string: */
    std::string s;                          // similar to vector<char> (but a string you can print in a whole)
    std::cout << s << '\n';

    /* std::deque */
    std::deque<double> deq{3.1, 2.3};       // Like vector, but:
    std::cout << deq[0]; // prints 3.1      // supports prepend in O(1)
    deq[1] = 32.0;       // assigns value   // faster resizes
    deq.push_back(2.2);  // append value    // high size overhead
    deq.push_front(1.1); // prepend value   // slightly slower access

    /* std::list */                         // A doubly-linked list.
    std::list<double> li{3.1, 2.3};         // Fast inserts/deletes anywhere.
    std::cout << *li.begin(); // prints 3.1 // no random access! []
    // li.insert(it, 2.2);  // insert value // 128bit size overhead per element
    li.push_back(2.2);      // append value // provides BidirectionalIterator

    /* std::forward_list */                 // A singly-linked list.
    std::forward_list<size_t> fwLi{3, 2};   // Fast inserts/deletes anywhere.
    std::cout << *fwLi.begin(); // prints 3 // no random access, no .size()!
    // fwLi.insert_after(it, 4); // append  // 64bit size overhead per element
                                            // provides ForwardIterator
}
