#ifndef UTILS_H
#define UTILS_H

#include <vector>

std::vector<int> gen_random_array(int num);
void print_array(std::vector<int> arr);
void print_array_to_file(std::vector<int> arr, std::ofstream &myfile);
        
#endif 
