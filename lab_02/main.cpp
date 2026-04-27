#include "list.h"

#include <iostream>
#include <vector>
#include <forward_list>

int main(void)
{
    List<int> l = {1,2,3,4,5,6,7};

    auto pos = l.begin();
    pos++;
    pos++;

    List<int> vec = {100, 101, 102, 103, 104, 105, 106, 107};

    auto start = vec.begin();
    start++;
    auto finish = vec.begin();
    finish++;
    finish++;
    finish++;
    finish++;

    l.insert_after(pos, start, finish);

    std::cout << l << "\n";

    std::forward_list<int> f_l = {1,2,3,4,5,6};

    std::vector<int> vect();

    return 0;
}