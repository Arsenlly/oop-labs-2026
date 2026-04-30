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
        Iterator(const std::shared_ptr<typename List<value_type>::Node>& node);
        Iterator(const Iterator<value_type> &it);

    #pragma endregion

    #pragma region Destructor

    ~Iterator() override = default;

    #pragma endregion

    #pragma region Operators
        Iterator<T>& operator=(const Iterator<value_type>& it);

        Iterator<value_type>& operator++();
        Iterator<value_type>& operator++(int);

        reference operator*() const;
        
        pointer operator->() const;
        
        operator bool() const noexcept;
        
        bool operator==(const Iterator<value_type> &it) const noexcept;
        bool operator!=(const Iterator<value_type> &it) const noexcept;

    #pragma endregion
        
    #pragma region GetNode

        std::shared_ptr<typename List<T>::Node> getNode();

    #pragma endregion
};

#include "iterator.hpp"

#endif