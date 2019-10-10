#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#include "gender.hpp"

void printPerson(std::tuple<std::string, uint16_t, Gender> person) {
    auto & [n, a, g] = person;
    std::cout << "Name " << n << ", age: " << a << ", gender: " << gender2string(g) << ".\n";
}

int main()
{
    std::vector<std::tuple<std::string, uint16_t, Gender>> persons{};

    std::string name{};
    uint16_t age{};
    std::string gender{};

    char yn = 'y';

    while(yn != 'n') {
        std::cout << "Please enter your NAME (one word), AGE and GENDER [female, male, diverse].\n";
        std::cin >> name >> age >> gender;

        std::tuple<std::string, uint16_t, Gender> person{name, age, string2gender(gender)};
        persons.push_back(person);

        std::cout << "Enter another person?[y/n]}\n";
        std::cin >> yn;
        while (yn != 'n' && yn != 'y')
        {
            std::cout << "Invalid character! Enter another person? [y/n]}\n";
            std::cin >> yn;
        }
    }

    auto sortPerson = [] (auto const & p1, auto const & p2)
    {
        // auto & [n1, a1, g1] = p1;
        // auto & [n2, a2, g2] = p2;
        // return std::tie(a1, n1) < std::tie(a2, n2);
        return (std::tie(std::get<1>(p1), std::get<0>(p1)) < std::tie(std::get<1>(p2), std::get<0>(p2)));
    };
    std::sort(persons.begin(), persons.end(), sortPerson);

    std::cout << "From the youngest person: \n";

    for (auto const & pers : persons)
        printPerson(pers);

    std::cout << "to the oldest person.\n";
}