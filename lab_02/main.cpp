#include <iostream>

#include "list.h"
#include <ranges>
#include <algorithm>
#include <vector>

int main(void)
{
    // // List<int> l1({1,2,3,4,5,6,7,8,9});

    // std::vector<int> vec({1,2,3,4,5,6,7,8,9});

    List<int> l1({1,2,3,4,5,6,7,8,9});

    l1.clear();

    try
    {
        std::cout << l1.front() << "\n";
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << "\n";
    }

    // List<int> l2({10,11,12,13,14,15,16});

    // List<int> l3(vec);
    // List<int> l4(l1);

    // l1 += l2;

    // // for (auto it = l.cbegin();it != l.cend();++it)
    // // {
    // //     std::cout << *it << "\n";
    // //     (*it)++;
    // // }

    // // for (auto it = l.cbegin();it != l.cend();++it)
    // // {
    // //     std::cout << *it << "\n";
    // // }

    // for(auto el : l1)
    // {
    //     std::cout << el << "\n";
    // }

    // // List<int> l2(l1);

    // for(auto el : l3)
    // {
    //     std::cout << el << "\n";
    // }

    // l1.clear();

    // std::cout << l1.is_empty();

    return 0;
}