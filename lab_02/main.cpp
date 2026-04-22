#include <iostream>

#include "list.h"
#include <ranges>
#include <algorithm>
#include <vector>
#include <forward_list>

int main(void)
{
    std::vector<int> vec = {1,2,3,4,5,6};
    List<in> l(vec);
    List<int> l1 = {1,2,3,4,5,6,7,8,9};
    for (auto& el : l)
    {
        el += 0.1;
    }
    for (auto el : l)
    {
        std::cout << el << "\n";
    }
    return 0;
}