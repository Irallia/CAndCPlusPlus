#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "uint8_t is of type: \t" << typeid(uint32_t).name() << " with the size of \t" << sizeof(uint32_t)*8
        << " bits, and values go from " << std::numeric_limits<uint32_t>::lowest() << " to " << UINT32_MAX << ".\n";

    const uint32_t POSTALCODE_MIN = 10115;
    const uint32_t POSTALCODE_MAX = 14199;

    char yn = 'y';

    std::vector<std::string> namesInBerlin;
    std::vector<uint32_t> postalCodes;

    std::string smallestPostalCodeName;
    uint32_t smallestPostalCode = std::numeric_limits<uint32_t>::max();

    while(yn != 'n') {
        std::cout << "Please enter your name (one word) and your postal code.\n";
        std::string name{};
        uint32_t postalCode{};
        std::cin >> name >> postalCode;

        if (postalCode < smallestPostalCode) {
            smallestPostalCode = postalCode;
            smallestPostalCodeName = name;
        }

        if (postalCode >= POSTALCODE_MIN && postalCode <= POSTALCODE_MAX) {
            std::cout << name << " lives in Berlin.\n";
            namesInBerlin.push_back(name);
            postalCodes.push_back(postalCode);
        } else {
            std::cout << name << " lives outside of Berlin.\n";
        }

        std::cout << "Enter another person?[y/n}\n";
        std::cin >> yn;
    }

    for(std::string name_i : namesInBerlin)
        std::cout << name_i << ", ";

    std::cout << " are living in Berlin.\n "
        << smallestPostalCodeName << " is the person with the smallest postal Code (" << smallestPostalCode << ").";

}