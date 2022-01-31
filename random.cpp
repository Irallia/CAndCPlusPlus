#include <chrono>       // chrono
#include <cstdlib>      // srand()
#include <functional>   // bind
#include <iostream>     // cout
#include <random>       // mt19937


int main()
{
    // rand() and srand()
    {
        std::srand(time(0));      // == srand(time(0)); mt_rand() returns a random uint32_t
        int random_variable = std::rand();
        std::cout << "Random value on [0 " << RAND_MAX << "]:\n" << random_variable << '\n';
    }

    // basic example for mt19937
    {
        std::mt19937 mt_rand(time(0));      // == srand(time(0)); = random uint32_t
        std::cout << mt_rand() << '\n';
    }

    // specific range (dice)
    {
        std::mt19937::result_type seed = time(0);
        auto dice_rand = std::bind(std::uniform_int_distribution<int>(1, 6), std::mt19937(seed));
        std::cout << dice_rand() << '\n';
    }

    // specific range (uniform dist)
    {
        std::mt19937::result_type seed = time(0);
        auto real_rand = std::bind(std::uniform_real_distribution<double>(0, 1), std::mt19937(seed));
        std::cout << real_rand() << '\n';
    }

    // the cpp 11 way:
    {
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::mt19937 mt_rand(seed);
        std::cout << mt_rand() << '\n';
    }

    return 0;
}
