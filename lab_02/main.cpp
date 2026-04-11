#include "list.h"

#include <iostream>

int main(void)
{
    List<int> l1(List<int>({1, 2, 3}));


    std::cout << l1.front();
    return 0;
}