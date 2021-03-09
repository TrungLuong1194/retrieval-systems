#include <iostream>
#include <vector>

#include "utils.h"

int main()
{
        std::vector<int> arr = gen_random_array(10);

        print_array(arr);

        return 0;
}

