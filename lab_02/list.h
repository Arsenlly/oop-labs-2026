#ifndef LIST_H__

#define LIST_H__

#include "base_list.h"

class List final: public BaseList
{
    public:
        List();

        ~List();
        
        List(const List& l);
        List& operator=(const List& l);

    private:

    protected:
        class Node
        {
        };
};

#include "list.hpp"

#endif