#include <iostream>
#include <vector>

#include "utils.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

std::vector<int> bubbleSort(std::vector<int> &arr)
{
	bool swapped;
	int numComps = 0;      // number of Comparations
	int numPerms = 0;      // number of Permutations
	std::vector<int> info; // array for store information of Comparations and Permutations

	for (int i = 0; i < arr.size()-1; i++)
	{
		swapped = false;

		for (int j = 0; j < arr.size()-i-1; j++)
		{
			numComps++;

			if (arr[j] > arr[j+1]) 
			{
				swap(&arr[j], &arr[j+1]);
				swapped = true;

				numPerms++;
			}
		}

		if (swapped == false)
			break;
	}
	
	info.push_back(numComps);
	info.push_back(numPerms);

	return info;
}

int main()
{
	// Generate random numbers array
	std::vector<int> arr = gen_random_array(10);

	// Bubble Sort
	std::vector<int> info = bubbleSort(arr);

	std::cout << "- Sorted array: \n";
	print_array(arr);

	std::cout << "\n- Number of Comparations: " << info[0] << "\n- Number of Permutations: " << info[1] << "\n";

	return 0;
}
