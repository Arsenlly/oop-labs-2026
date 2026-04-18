#ifndef CONST_ITERATOR_H__

#define CONST_ITERATOR_H__

#include "base_iterator.h"

template<typename T>
class List;

template<typename T>
class ConstIterator: public BaseIterator<T>
{
    public:
        ConstIterator() = default;
        ConstIterator(const std::shared_ptr<typename List<T>::Node>& node);
        ConstIterator(const ConstIterator<T> &it);

        ~ConstIterator() override = default;

        ConstIterator<T>& operator++();
        ConstIterator<T>& operator++(int);

        const T& operator*();

        operator bool();

        bool operator==(const ConstIterator<T> &it);
        bool operator!=(const ConstIterator<T> &it);
};

#include "const_iterator.hpp"

#endif