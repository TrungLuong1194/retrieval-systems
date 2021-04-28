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

std::vector<int> selectionSort(std::vector<int> &arr)
{
	int numComps = 0;      // number of Comparations
	int numPerms = 0;      // number of Permutations
	std::vector<int> info; // array for store information of Comparations and Permutations

	for (int i = 0; i < arr.size()-1; i++)
	{
		int jMin = i;

		for (int j = i+1; j < arr.size(); j++)
		{
			numComps++;

			if (arr[j] < arr[jMin])
				jMin = j;
		}

		if (jMin != i)
		{
			swap(&arr[i], &arr[jMin]);

			numPerms++;
		}
	}

	info.push_back(numComps);
	info.push_back(numPerms);

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
 	myfile << "\nSelection Sort:\n";
 	myfile << "\n\t- Original array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

	// Selection Sort
	std::vector<int> info = selectionSort(arr);

	// std::cout << "- Sorted array: \n";
	// print_array(arr);
	// std::cout << "\n- Number of Comparations: " << info[0] << "\n- Number of Permutations: " << info[1] << "\n";

	// Save to file
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << info[0] << "\n\t- Number of Permutations: " << info[1] << "\n";

 	// Sorting when array is in place
 	info = selectionSort(arr);

 	myfile << "\n- Sorting when array is in place:\n";
 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << info[0] << "\n\t- Number of Permutations: " << info[1] << "\n";

 	// Sorting when array reversed
 	std::reverse(arr.begin(), arr.end());

 	myfile << "\n- Sorting when array reversed:\n";
 	myfile << "\n\t- Reversed array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);

 	info = selectionSort(arr);

 	myfile << "\n\t- Sorted array:\n";
 	myfile << "\t";
 	print_array_to_file(arr, myfile);
 	myfile << "\n\t- Number of Comparations: " << info[0] << "\n\t- Number of Permutations: " << info[1] << "\n";

 	myfile.close();

	return 0;
}
