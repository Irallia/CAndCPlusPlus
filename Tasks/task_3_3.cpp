#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<bool> people_with_hat; // whether person x has hat
    people_with_hat.resize(1'000'000); // lot's of people
    people_with_hat[47] = true;
    people_with_hat[120] = true; // only few people have hat

    size_t min = 0;
    size_t max = 1'000'000;

    std::set<size_t> people_with_hat_set{}; // whether person x has hat
    people_with_hat_set.insert(47);
    people_with_hat_set.insert(120);
    std::set<size_t>::iterator s_it;
    for (size_t i = min; i < max; ++i)
    {
        s_it = std::find(people_with_hat_set.begin(), people_with_hat_set.end(), i);
        if (s_it != people_with_hat_set.end())
            std::cout << "Found someone with a hat: " << i << '\n';
    }

    std::unordered_set<size_t> people_with_hat_uSet{}; // whether person x has hat
    people_with_hat_uSet.insert(47);
    people_with_hat_uSet.insert(120);
    std::unordered_set<size_t>::iterator us_it;
    for (size_t i = min; i < max; ++i)
    {
        us_it = std::find(people_with_hat_uSet.begin(), people_with_hat_uSet.end(), i);
        if (us_it != people_with_hat_uSet.end())
            std::cout << "Found someone with a hat: " << i << '\n';
    }

    /*
    2. How much space do you assume the above example uses? How much would it consume with the sets?
    3. What if you want to take into account that people can have multiple hats?
        I would use a set of tuples and the find_if function.
    */
}