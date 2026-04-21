#ifndef BASE_ITERATOR_H__

#define BASE_ITERATOR_H__

#include <memory>

template<ListType T>
class List;

template<ListType T>
class BaseIterator
{   
    public:
        BaseIterator() = default;
        virtual ~BaseIterator() = 0;

    protected:
        std::weak_ptr<typename List<T>::Node> curr;

};

#include "base_iterator.hpp"

#endif