#include "list.h"

#include <iostream>
#include <vector>

int main(void)
{
    List<int> l = {1, 2,3,4,5,6,7};

    std::vector<int> vec = {10,11,12,13,14,15,16,17};

    List<int> l2 = {22, 23,24,25,26};

    List<int> l1;

    l1 = l.merge(vec);

    l1 = l1.merge(l2);

    std::cout << l1 << "\n";


    return 0;
}