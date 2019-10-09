#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class Gender
{
    FEMALE, MALE, DIVERSE
};

std::string giveString(Gender const g)
{
    switch (g)
    {
    case Gender::MALE:
        return "male";
    case Gender::FEMALE:
        return "female";
    case Gender::DIVERSE:
        return "diverse";
    }
    return "";
}

Gender getGenderFromString(std::string const sGender)
{
    if (sGender == "male")
    {
        return Gender::MALE;
    }
    else if (sGender == "female")
    {
        return Gender::FEMALE;
    }
    else
    {
        return Gender::DIVERSE;
    }
}

struct Person
{
    std::string name;
    uint16_t age;
    Gender gender;

    void print()
    {
        std::cout << "Name " << this->name << ", age: " << this->age << ", gender: " << giveString(this->gender) << ".\n";
    }

    bool operator<(Person a) const
    {
        return this->age < a.age;
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
        persons.push_back(Person{name, age, getGenderFromString(gender)});

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