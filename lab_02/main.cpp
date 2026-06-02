#include "list.h"

#include <iostream>
#include <vector>

int main(void)
{
    // std::vector<int> v = {1,2,3,4,5,6,7,8,9};

    // int arr[] = {1,2,3,4,5,6,7,8,9,10};

    // auto beg = v.cbegin();

    // auto end = v.cbegin();

    // end++;
    // end++;
    // end++;


    // List<int> l(10, 500);

    List<int> l1({1,2,3,4,5,6,7});
    List<int> l2({1,2,7,4,5,6,7});

    std::cout << (l1 == l2) << "\n";

    return 0;
}