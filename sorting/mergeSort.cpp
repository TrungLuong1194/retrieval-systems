#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::reverse

#include "utils.h"

void merge(std::vector<int> &arr, int l, int m, int r, int &numComps, int &numSwaps)
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
			arr[k] = L[i];
			i++;

			numSwaps++;
		} 
		else
		{
			arr[k] = R[j];
			j++;

			numSwaps++;
		}

		k++;
	}

	// copy the remaining elements of subarrays
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;

		numSwaps++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;

		numSwaps++;
	}
}

void mergeSort(std::vector<int> &arr, int l, int r, int &numComps, int &numSwaps)
{
	if (l < r)
	{
        int numComps1 = 0;
	    int numComps2 = 0;
	    int numComps3 = 0;
	    int numSwaps1 = 0;
	    int numSwaps2 = 0;
	    int numSwaps3 = 0;

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m, numComps1, numSwaps1);
		mergeSort(arr, m+1, r, numComps2, numSwaps2);
		merge(arr, l, m, r, numComps3, numSwaps3);

		numComps += (numComps1 + numComps2 + numComps3);
		numSwaps += (numSwaps1 + numSwaps2 + numSwaps3);
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
	int numComps = 0;
    int numSwaps = 0;

	mergeSort(arr, 0, arr.size()-1, numComps, numSwaps);

	// std::cout << "- Sorted array: \n";
	// print_array(arr);
	// std::cout << "\n- Number of Comparations: " << numComps << "\n- Number of Swaps: " << numSwaps << "\n";

	// Save to file
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps << "\n\t- Number of Swaps: " << numSwaps << "\n";

 	// Sorting when array is in place
 	int numComps1 = 0;
    int numSwaps1 = 0;

	mergeSort(arr, 0, arr.size()-1, numComps1, numSwaps1);

 	myfile << "\n- Sorting when array is in place:\n";
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps1 << "\n\t- Number of Swaps: " << numSwaps1 << "\n";

 	// Sorting when array reversed
 	std::reverse(arr.begin(), arr.end());

 	myfile << "\n- Sorting when array reversed:\n";
 	myfile << "\n\t- Reversed array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

 	int numComps2 = 0;
    int numSwaps2 = 0;

	mergeSort(arr, 0, arr.size()-1, numComps2, numSwaps2);

 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << numComps2 << "\n\t- Number of Swaps: " << numSwaps2 << "\n";

 	myfile.close();

	return 0;
}
