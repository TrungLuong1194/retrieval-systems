#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime>   // for std::time()
#include <vector>

#include "utils.h"

unsigned int PRNG()
{
    // our initial starting seed is 5323
    static unsigned int seed{ 5323 };

    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // hard for someone to casually predict what the next number is
    // going to be from the previous one.
    seed = 8253729 * seed + 2396403;

    // Take the seed and return a value between 0 and 32767
    return seed % 32768;
}

std::vector<int> gen_random_array(int num)
{
	std::vector<int> arr;

        for (int i = 1; i <= num; i++)
                arr.push_back(PRNG());

        return arr;
}

void print_array(std::vector<int> arr)
{
        for (int i = 0; i < arr.size(); i++)
	{
		if (i == arr.size() - 1)
			std::cout << arr[i];
		else
			std::cout << arr[i] << " - ";
	}

	std::cout << "\n";
}

void print_hello()
{
        std::cout << "Hello";
}
