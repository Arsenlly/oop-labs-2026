#include "list.h"

#include <gtest/gtest.h>
#include <vector>

#include <iostream>

TEST(Constructors, empty_list)
{
    List<int> l;
    ASSERT_EQ(l.size(), 0);
}

TEST(Constructors, list_from_array)
{
    int n = 9;
    int arr_int[] = {1,2,3,4,5,6,7,8,9};
    double arr_double[] = {1.4,2.1,3.1,4.1,5.2,6.1,7.1,8.1,9.1};
    List<int> answer = {1,2,3,4,5,6,7,8,9};

    List<int> l1(n, arr_int);
    List<int> l2(n, arr_double);
    
    ASSERT_EQ(l1, answer);
    ASSERT_EQ(l2, answer);
}

TEST(Constructors, list_from_vector)
{
    std::vector<int> v_int = {1,2,3,4,5,6,7,8,9};
    std::vector<double> v_double = {1.4,2.1,3.1,4.1,5.2,6.1,7.1,8.1,9.1};
    List<int> answer = {1,2,3,4,5,6,7,8,9};

    List<int> l1(v_int);
    List<int> l2(v_double);
    
    ASSERT_EQ(l1, answer);
    ASSERT_EQ(l2, answer);
}

TEST(Constructors, list_copy)
{
    List<int> l1 = {1,2,3,4,5,6,7,8,9};
    List<int> l2(l1);
    List<int> answer = {1,2,3,4,5,6,7,8,9};

    ASSERT_EQ(l2, answer);
    ASSERT_EQ(l1, answer);
}

TEST(Constructors, list_move)
{
    List<int> l1 = {1,2,3,4,5,6,7,8,9};
    List<int> l2(std::move(l1));
    List<int> answer = {1,2,3,4,5,6,7,8,9};

    ASSERT_EQ(l2, answer);
    ASSERT_EQ(l1.size(), 0);
}

TEST(Constructors, list_from_initializer_list)
{
    List<int> l1({1,2,3,4,5,6,7,8,9});
    List<int> answer = {1,2,3,4,5,6,7,8,9};

    ASSERT_EQ(l1, answer);
}

TEST(Constructors, list_from_iterators)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    List<int> l1(vec.cbegin(), vec.cend());
    List<int> answer = {1,2,3,4,5,6,7,8,9};

    ASSERT_EQ(l1, answer);
}

TEST(Get_elements, front)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};

    ASSERT_EQ(l.front(), 1);
}

TEST(Get_elements, back)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};

    ASSERT_EQ(l.back(), 9);
}

TEST(Remove_elements, pop_front)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    List<int> answer = {2,3,4,5,6,7,8,9};

    ASSERT_EQ(l.pop_front(), 1);
    ASSERT_EQ(l, answer);
}

TEST(Remove_elements, pop_back)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    List<int> answer = {1,2,3,4,5,6,7,8};

    ASSERT_EQ(l.pop_back(), 9);
    ASSERT_EQ(l, answer);
}

TEST(Remove_elements, remove)
{
    List<int> l = {1,2,3,4,5,9,6,7,8,9};
    List<int> answer = {1,2,3,4,5,6,7,8};

    l.remove(9);
    ASSERT_EQ(l, answer);
}

TEST(Remove_elements, remove_after)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    List<int> answer = {1,2,4,5,6,7,8,9};

    auto it = l.begin();
    it++;
    l.remove_after(it);
    ASSERT_EQ(l, answer);
}

TEST(Add, push_front)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    List<int> answer = {0,1,2,3,4,5,6,7,8,9};

    l.push_front(0);
    ASSERT_EQ(l, answer);
}

TEST(Add, push_back)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    List<int> answer = {1,2,3,4,5,6,7,8,9,10};

    l.push_back(10);
    ASSERT_EQ(l, answer);
}

TEST(Add, insert_after_el)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    List<int> answer = {1,2,10,3,4,5,6,7,8,9};

    auto it = l.begin();
    it++;
    l.insert_after(it, 10);
    ASSERT_EQ(l, answer);
}

TEST(Add, insert_after_list)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    List<int> l1 = {10,11,12,13};
    List<int> answer = {1,2,10,11,12,13,3,4,5,6,7,8,9};

    auto it = l.begin();
    it++;
    l.insert_after(it, l1);
    ASSERT_EQ(l, answer);
}

TEST(Add, insert_after_vector)
{
    List<int> l = {1,2,3,4,5,6,7,8,9};
    std::vector<int> vec = {10,11,12,13};
    List<int> answer = {1,2,10,11,12,13,3,4,5,6,7,8,9};

    auto it = l.begin();
    it++;
    l.insert_after(it, vec);
    ASSERT_EQ(l, answer);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}