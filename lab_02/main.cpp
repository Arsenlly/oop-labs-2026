#include <iostream>

#include "list.h"
#include <ranges>
#include <algorithm>
#include <vector>

int main(void)
{
    List<int> l1 = {100,2,3,4,5,6,7,8,9};

    // List<int> l2(l1);

    // for(auto el : l2)
    // {
    //     std::cout << el << "\n";
    // }

    // std::cout << l1.has(300) << "\n";

    l1.clear();

    if (l1)
        std::cout << "positive\n";
    else
        std::cout << "negative\n";

    return 0;
}