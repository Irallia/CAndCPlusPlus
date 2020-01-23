#include <algorithm>    // for std::sort
#include <iostream>     // for std::cout, std::cin
#include <tuple>        // for std::tie
#include <vector>       // for std::vector

#include "gender.hpp"

struct Person
{
    std::string name;
    uint16_t age;
    Gender gender;

    void print()
    {
        std::cout << "Name " << name << ", age: " << age << ", gender: " << gender2string(gender) << ".\n";
    }

    bool operator<(Person other) const
    {
        return std::tie(age, name) < std::tie(other.age, name); // use tuple to compare first by age, than by name.
    }
};

int main() {

    std::vector<Person> persons{};

    std::string name{};
    uint16_t age{};
    std::string gender{};

    char yn = 'y';

    while(yn != 'n') {
        std::cout << "Please enter your NAME (one word), AGE and GENDER [female, male, diverse].\n";
        std::cin >> name >> age >> gender;
        persons.push_back(Person{name, age, string2gender(gender)});

        std::cout << "Enter another person?[y/n]}\n";
        std::cin >> yn;
        while (yn != 'n' && yn != 'y')
        {
            std::cout << "Invalid character! Enter another person? [y/n]}\n";
            std::cin >> yn;
        }
    }

    std::sort(persons.begin(), persons.end());

    std::cout << "The youngest person is: \n";
    persons.front().print();
    std::cout << " and the oldest person is: \n";
    persons.back().print();

    auto sortPerson = [] (auto const & p1, auto const & p2) { return p1.age > p2.age; };
    std::sort(persons.begin(), persons.end(), sortPerson);

    std::cout << "The oldest person is: \n";
    persons.front().print();
    std::cout << " and the youngest person is: \n";
    persons.back().print();

    // ToDo:
    // Which solution do you think is better? How difficult would it be to sort by name (alphabetically) instead?

}
