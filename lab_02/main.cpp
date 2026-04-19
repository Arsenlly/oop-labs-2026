#include <iostream>

#include "list.h"
#include <ranges>
#include <algorithm>
#include <vector>

int main(void)
{
    List<int> l1({100,2,3,4,5,6,7,8,9});

    // List<int> l2(vec.begin(), vec.end());

    auto it = l1.begin();

    try
    {
        std::cout << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << "2\n";
        std::cerr << e.what() << '\n';
    }
    
    l1.pop_front();

    try
    {
        std::cout << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << "2\n";
        std::cerr << e.what() << '\n';
    }
    
    // int a[] = {1,2,3,4,5,6,7,8,9};
    
    // List<int> l(9, a);

    // for(auto el : l2)
    // {
    //     std::cout << el << "\n";
    // }

    return 0;
}