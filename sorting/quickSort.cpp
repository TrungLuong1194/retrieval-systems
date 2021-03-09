#include <iostream>
#include <fstream>
#include <vector>

#include "utils.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Partition function: takes the last element as pivot*/
int partition(std::vector<int> &arr, int low, int high, int &numComps, int &numPerms)
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

			numPerms++;
		}
	}

	swap(&arr[i + 1], &arr[high]);
	numPerms++;

	return (i + 1);
}

void quickSort(std::vector<int> &arr, int low, int high, int &numComps, int &numPerms)
{
	if (low < high)
	{
		int numComps1 = 0;
	    int numComps2 = 0;
	    int numComps3 = 0;
	    int numPerms1 = 0;
	    int numPerms2 = 0;
	    int numPerms3 = 0;

		int par = partition(arr, low, high, numComps1, numPerms1);

		quickSort(arr, low, par - 1, numComps2, numPerms2);
		quickSort(arr, par + 1, high, numComps3, numPerms3);

		numComps += (numComps1 + numComps2 + numComps3);
		numPerms += (numPerms1 + numPerms2 + numPerms3);
	}
}


int main()
{
	// Generate random numbers array
	std::vector<int> arr = gen_random_array(20);

	// Quick Sort
	int numComps = 0;
    int numPerms = 0;

	quickSort(arr, 0, arr.size()-1, numComps, numPerms);

	std::cout << "- Sorted array: \n";
	print_array(arr);

	std::cout << "\n- Number of Comparations: " << numComps << "\n- Number of Permutations: " << numPerms << "\n";

	// Open a file to save result
	std::ofstream myfile;

 	myfile.open("result.txt", std::ios::app);

 	myfile << "\nQuick Sort:\n";
 	myfile << "\n- Number of Comparations: " << numComps << "\n- Number of Permutations: " << numPerms << "\n";

 	myfile.close();

	return 0;
}
