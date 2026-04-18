#include <iostream>

#include "list.h"
#include <ranges>
#include <algorithm>
#include <vector>

int main(void)
{
    List<int> l1({1,2,3,4,5,6,7,8,9});

    List<int> l2(l1.cbegin(), l1.cend());

    for(auto el : l2)
    {
        std::cout << el << "\n";
    }

    return 0;
}