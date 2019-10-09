#include <iostream>
#include <typeinfo>
#include <limits>

void print_stat(t) {
    // https://en.cppreference.com/w/cpp/types/numeric_limits/lowest
    std::cout << "size: " << sizeof(t) * 8
            << " max: " << std::numeric_limits<t>::max()
            << " min: " << std::numeric_limits<t>::lowest()
            << "\n";
}

int main()
{
    print_stat(char);
    /**/
    std::cout << "char is of type: " << typeid(char).name() << " with the size of \t\t" << sizeof(char)*8
        << " bits,\t\t and values go from " << CHAR_MIN << " to " << CHAR_MAX << "\n";
    std::cout << "short is of type: " << typeid(short).name() << " with the size of \t\t" << sizeof(short)*8
        << " bits,\t and values go from " << SHRT_MIN << " to " << SHRT_MAX << "\n";
    std::cout << "int is of type: " << typeid(int).name() << " with the size of \t\t" << sizeof(int)*8
        << " bits,\t and values go from " << INT_MIN << " to " << INT_MAX << "\n";
    std::cout << "long is of type: " << typeid(long).name() << " with the size of \t\t" << sizeof(long)*8
        << " bits,\t and values go from " << LONG_MIN << " to " << LONG_MAX << "\n";
    std::cout << "long long is of type: " << typeid(long long).name() << " with the size of \t" << sizeof(long long)*8
        << " bits,\t and values go from " << LONG_LONG_MIN << " to " << LONG_LONG_MAX << "\n";
    std::cout << "unsigned is of type: " << typeid(unsigned).name() << " with the size of \t" << sizeof(unsigned)*8
        << " bits,\t where the smallest char value is " << 0 << " to " << UCHAR_MAX
        << "\n and the smallest short value is \t" << 0 << " to " << USHRT_MAX
        << "\n and the smallest int value is \t\t" << 0 << " to " << UINT_MAX
        << "\n and the smallest long value is \t" << 0 << " to " << ULONG_MAX
        << "\n and the smallest long long value is \t" << 0 << " to " << ULLONG_MAX << "\n";

    // int i = INT_MAX + 1;     // error: integer overflow in expression of type 'int' results in '-2147483648'
    // std::cout << "INT_MAX + 1 == INT_MIN == " << i;
}