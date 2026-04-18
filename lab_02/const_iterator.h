#ifndef CONST_ITERATOR_H__

#define CONST_ITERATOR_H__

#include "base_iterator.h"

template<typename T>
class List;

template<typename T>
class ConstIterator: public BaseIterator<T>
{
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = std::shared_ptr<T>;
        using reference = const T&;
        using iterator_category = std::forward_iterator_tag;

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