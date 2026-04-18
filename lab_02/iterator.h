#ifndef ITERATOR_H__

#define ITERATOR_H__

#include "base_iterator.h"

template<typename T>
class List;

template<typename T>
class Iterator: public BaseIterator<T>
{
    public:
        Iterator() = default;
        Iterator(const std::shared_ptr<typename List<T>::Node>& node);
        Iterator(const Iterator<T> &it);

        ~Iterator() override = default;

        Iterator<T>& operator++();
        Iterator<T>& operator++(int);

        T& operator*();

        operator bool();

        bool operator==(const Iterator<T> &it);
        bool operator!=(const Iterator<T> &it);
};

#include "iterator.hpp"

#endif