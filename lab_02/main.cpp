#include <iostream>

#include "list.h"
#include <ranges>
#include <algorithm>
#include <vector>
#include <forward_list>

int main(void)
{
    List<int> l = {1,2};

    auto it = l.begin();
    
    it++;

    l.remove_after(it);

    // std::vector vec = {1,2,3,4,5,6,7,8,9};

    // l += vec;

    // for (auto el : l)
    // {
    //     std::cout << el << "\n";
    // }

    std::cout << l << "\n";
    return 0;
}