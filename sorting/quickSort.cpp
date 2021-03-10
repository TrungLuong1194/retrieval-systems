#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::reverse

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
	int numComps = 0;
    int numPerms = 0;

	quickSort(arr, 0, arr.size()-1, numComps, numPerms);

	// std::cout << "- Sorted array: \n";
	// print_array(arr);
	// std::cout << "\n- Number of Comparations: " << numComps << "\n- Number of Permutations: " << numPerms << "\n";

	// Save to file
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Permutations: " << numPerms << "\n";

 	// Sorting when array is in place
 	int numComps1 = 0;
    int numPerms1 = 0;

	quickSort(arr, 0, arr.size()-1, numComps1, numPerms1);

 	myfile << "\n- Sorting when array is in place:\n";
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps1 << "\n\t- Number of Permutations: " << numPerms1 << "\n";

 	// Sorting when array reversed
 	std::reverse(arr.begin(), arr.end());

 	myfile << "\n- Sorting when array reversed:\n";
 	myfile << "\n\t- Reversed array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

 	int numComps2 = 0;
    int numPerms2 = 0;

	quickSort(arr, 0, arr.size()-1, numComps2, numPerms2);

 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps2 << "\n\t- Number of Permutations: " << numPerms2 << "\n";

 	myfile.close();

	return 0;
}
