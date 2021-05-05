#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::reverse

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

		numComps++;

		while (j >=0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;

			numSwaps++;

			if (j >= 0)
				numComps++;
		}

		arr[j + 1] = key;

		if ((j + 1) != i)
			numSwaps++;
	}

	info.push_back(numComps);
	info.push_back(numSwaps);

	return info;
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
 	myfile << "\nInsertion Sort:\n";
 	myfile << "\n\t- Original array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

	// Insertion Sort
	std::vector<int> info = insertionSort(arr);

	// std::cout << "- Sorted array:\n";
	// print_array(arr);
	// std::cout << "\n- Number of Comparations: " << info[0] << "\n- Number of Swaps: " << info[1] << "\n";

	// Save to file
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << info[0] << "\n\t- Number of Swaps: " << info[1] << "\n";

 	// Sorting when array is in place
 	info = insertionSort(arr);

 	myfile << "\n- Sorting when array is in place:\n";
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << info[0] << "\n\t- Number of Swaps: " << info[1] << "\n";

 	// Sorting when array reversed
 	std::reverse(arr.begin(), arr.end());

 	myfile << "\n- Sorting when array reversed:\n";
 	myfile << "\n\t- Reversed array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

 	info = insertionSort(arr);

 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << info[0] << "\n\t- Number of Swaps: " << info[1] << "\n";

 	myfile.close();

	return 0;
}
