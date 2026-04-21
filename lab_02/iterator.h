#ifndef ITERATOR_H__

#define ITERATOR_H__

#include "base_iterator.h"
#include "iterator_exception.h"

template<ListType T>
class List;

template<ListType T>
class Iterator: public BaseIterator<T>
{
    public:

    #pragma region Aliases

        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = std::shared_ptr<value_type>;
        using reference = value_type&;
        using iterator_category = std::forward_iterator_tag;
    
    #pragma endregion

    public:

    #pragma region Constructors

        Iterator() = default;
        Iterator(const std::shared_ptr<typename List<T>::Node>& node);
        Iterator(const Iterator<T> &it);
        Iterator(Iterator<T> &&it);

    #pragma endregion

    ~Iterator() override = default;

    #pragma region Operators
        Iterator<T>& operator=(const Iterator<T>& it);
        Iterator<T>& operator=(Iterator<T>&& it);

        Iterator<T>& operator++();
        Iterator<T>& operator++(int);

        T& operator*();
        
        std::shared_ptr<T>& operator->();
        
        operator bool() const noexcept;
        
        bool operator==(const Iterator<T> &it) const noexcept;
        bool operator!=(const Iterator<T> &it) const noexcept;

        
    #pragma endregion
        
        std::shared_ptr<typename List<T>::Node> getNode();
};

#include "iterator.hpp"

#endif