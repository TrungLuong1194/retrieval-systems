#include <iostream>
#include <vector>

#include "utils.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Partition function: takes the last element as pivot*/
int partition(std::vector<int> &arr, int low, int high, int &numComps, int &numSwaps)
{
	int pivot = arr[high];
	int i = (low - 1); // index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		numComps++;

		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);

			numSwaps++;
		}
	}

	swap(&arr[i + 1], &arr[high]);
	numSwaps++;

	return (i + 1);
}

void quickSort(std::vector<int> &arr, int low, int high, int &numComps, int &numSwaps)
{
	if (low < high)
	{
		int numComps1 = 0;
	    int numComps2 = 0;
	    int numComps3 = 0;
	    int numSwaps1 = 0;
	    int numSwaps2 = 0;
	    int numSwaps3 = 0;

		int par = partition(arr, low, high, numComps1, numSwaps1);

		quickSort(arr, low, par - 1, numComps2, numSwaps2);
		quickSort(arr, par + 1, high, numComps3, numSwaps3);

		numComps += (numComps1 + numComps2 + numComps3);
		numSwaps += (numSwaps1 + numSwaps2 + numSwaps3);
	}
}


int main()
{
	// Generate random numbers array
	std::vector<int> arr = gen_random_array(10);

	// Quick Sort
	int numComps = 0;
    int numSwaps = 0;

	quickSort(arr, 0, arr.size()-1, numComps, numSwaps);

	std::cout << "- Sorted array: \n";
	print_array(arr);

	std::cout << "\n- Number of Comparations: " << numComps << "\n- Number of Swaps: " << numSwaps << "\n";

	return 0;
}
