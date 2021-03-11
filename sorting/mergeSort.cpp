#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::reverse

#include "utils.h"

int numComps = 0;
int numSwaps = 0;

void merge(std::vector<int> &arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// create tmp arrays
	int L[n1], R[n2];

	// copy data to tmp arrays
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];

	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0; // initial index of first subarray
	int j = 0; // initial index of second subarray
	int k = l; // initial index of merged subarray

	while (i < n1 && j < n2)
	{
		numComps++;

		if (L[i] <= R[j])
		{
			if (arr[k] != L[i])
				numSwaps++;

			arr[k] = L[i];
			i++;
		} 
		else
		{
			if (arr[k] != R[j])
				numSwaps++;

			arr[k] = R[j];
			j++;
		}

		k++;
	}

	// copy the remaining elements of subarrays
	while (i < n1)
	{
		if (arr[k] != L[i])
			numSwaps++;

		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		if (arr[k] != R[j])
			numSwaps++;

		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int> &arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
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
 	myfile << "\nMerge Sort:\n";
 	myfile << "\n\t- Original array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

	// Merge Sort
	mergeSort(arr, 0, arr.size()-1);

	// std::cout << "- Sorted array: \n";
	// print_array(arr);
	// std::cout << "\n- Number of Comparations: " << numComps << "\n- Number of Swaps: " << numSwaps << "\n";

	// Save to file
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Swaps: " << numSwaps << "\n";

 	// Sorting when array is in place
 	numComps = 0;
    numSwaps = 0;

	mergeSort(arr, 0, arr.size()-1);

 	myfile << "\n- Sorting when array is in place:\n";
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Swaps: " << numSwaps << "\n";

 	// Sorting when array reversed
 	std::reverse(arr.begin(), arr.end());

 	myfile << "\n- Sorting when array reversed:\n";
 	myfile << "\n\t- Reversed array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

 	numComps = 0;
    numSwaps = 0;

	mergeSort(arr, 0, arr.size()-1);

 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Swaps: " << numSwaps << "\n";

 	myfile.close();

	return 0;
}
