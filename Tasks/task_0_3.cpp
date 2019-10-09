#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

int main()
{
    std::cout << "Enter a string and followed by [RETURN] a number\n";

    std::string s{};
    int index{};
    std::cin >> s >> index;

    std::cout << "The i'th character is: " << s[index] << " and again, it is " << s.at(index) << '\n';
    // If the number is to big, nothing happens for [], but for "at()":
    // 'std::out_of_range' what():  basic_string::at: __n (which is 8) >= this->size() (which is 5)
    std::cout << "Still alive!";

    // -> at() is saver but slower, because it does the checking.

}