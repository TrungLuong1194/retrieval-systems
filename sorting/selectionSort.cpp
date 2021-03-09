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
	std::vector<int> arr = gen_random_array(20);

	// Selection Sort
	std::vector<int> info = selectionSort(arr);

	std::cout << "- Sorted array: \n";
	print_array(arr);

	std::cout << "\n- Number of Comparations: " << info[0] << "\n- Number of Permutations: " << info[1] << "\n";

	// Open a file to save result
	std::ofstream myfile;

 	myfile.open("result.txt", std::ios::app);

 	myfile << "\nSelection Sort:\n";
 	myfile << "\n- Number of Comparations: " << info[0] << "\n- Number of Permutations: " << info[1] << "\n";

 	myfile.close();

	return 0;
}
