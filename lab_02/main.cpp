#include "list.h"

#include <iostream>
#include <vector>
#include <forward_list>

#include <string_view>

int main(void)
{
    List<int> l1 = {50, 60, 70, 80, 90, 100};

    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};

    List<int> l2;

    l2 = l1 + vec;

    std::cout << l2 << "\n";

    std::cout << l2.size() << "\n";

    return 0;
}