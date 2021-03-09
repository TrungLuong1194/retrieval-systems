#include <iostream>
#include <vector>

#include "utils.h"

std::vector<int> insertionSort(std::vector<int> &arr)
{
	int numComps = 0;      // number of Comparations
	int numSwaps = 0;      // number of Swaps
	std::vector<int> info; // array for store information of Comparations and Swaps
	int key, j;	

	for (int i = 1; i < arr.size(); i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >=0 && arr[j] > key)
		{
			numComps++;

			arr[j + 1] = arr[j];
			j--;

			numSwaps++;
		}

		arr[j + 1] = key;
		numSwaps++;
	}

	info.push_back(numComps);
	info.push_back(numSwaps);

	return info;
}

int main()
{
	// Generate random numbers array
	std::vector<int> arr = gen_random_array(10);

	// Insertion Sort
	std::vector<int> info = insertionSort(arr);

	std::cout << "- Sorted array: \n";
	print_array(arr);

	std::cout << "\n- Number of Comparations: " << info[0] << "\n- Number of Swaps: " << info[1] << "\n";

	return 0;
}
