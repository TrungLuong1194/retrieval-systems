#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::reverse

#include "utils.h"

int numComps = 0;
int numPerms = 0;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Partition function: takes the last element as pivot*/
int partition(std::vector<int> &arr, int lo, int hi)
{
	int pivot = arr[hi];
	int i = (lo - 1); // index of smaller element

	for (int j = lo; j <= hi - 1; j++)
	{
		numComps++;

		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);

			if (i != j)
				numPerms++;
		}
	}

	swap(&arr[i + 1], &arr[hi]);
	
	if ((i + 1) != hi)
		numPerms++;

	return (i + 1);
}

void quickSort(std::vector<int> &arr, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(arr, lo, hi);

		quickSort(arr, lo, p - 1);
		quickSort(arr, p + 1, hi);
	}
}


int main()
{
	// Generate random numbers array
	std::vector<int> arr = gen_random_array(40);

	// Open a file to save result
	std::ofstream myfile;

	// Save to file
 	myfile.open("result.txt", std::ios::app);
 	myfile << "\n----------------------------------------------------\n";
 	myfile << "\nQuick Sort:\n";
 	myfile << "\n\t- Original array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

	// Quick Sort
	quickSort(arr, 0, arr.size()-1);

	// std::cout << "- Sorted array: \n";
	// print_array(arr);
	// std::cout << "\n- Number of Comparations: " << numComps << "\n- Number of Permutations: " << numPerms << "\n";

	// Save to file
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Permutations: " << numPerms << "\n";

 	// Sorting when array is in place
 	numComps = 0;
    numPerms = 0;

	quickSort(arr, 0, arr.size()-1);

 	myfile << "\n- Sorting when array is in place:\n";
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Permutations: " << numPerms << "\n";

 	// Sorting when array reversed
 	std::reverse(arr.begin(), arr.end());

 	myfile << "\n- Sorting when array reversed:\n";
 	myfile << "\n\t- Reversed array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

 	numComps = 0;
    numPerms = 0;

	quickSort(arr, 0, arr.size()-1);

 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Permutations: " << numPerms << "\n";

 	myfile.close();

	return 0;
}
