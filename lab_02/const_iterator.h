#ifndef CONST_ITERATOR_H__

#define CONST_ITERATOR_H__

#include "base_iterator.h"

template<ListType T>
class List;

template<ListType T>
class ConstIterator: public BaseIterator<T>
{
    public:

    #pragma region Aliases

        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = const std::shared_ptr<value_type>;
        using reference = const value_type&;
        using iterator_category = std::forward_iterator_tag;
    
    #pragma endregion

    public:

    #pragma region Constructors

        ConstIterator() = default;
        ConstIterator(const std::shared_ptr<typename List<value_type>::Node>& node);
        ConstIterator(const ConstIterator<value_type> &it);

    #pragma endregion

    #pragma region Destructor

    ~ConstIterator() override = default;

    #pragma endregion

    #pragma region Operators
        ConstIterator<value_type>& operator=(const ConstIterator<value_type>& it);

        ConstIterator<value_type>& operator++();
        ConstIterator<value_type>& operator++(int);

        reference operator*() const;
        
        pointer operator->() const;
        
        operator bool() const noexcept;
        
        bool operator==(const ConstIterator<value_type> &it) const noexcept;
        bool operator!=(const ConstIterator<value_type> &it) const noexcept;

    #pragma endregion

    #pragma region GetNode

    std::shared_ptr<const typename List<T>::Node> getNode() const;

    #pragma endregion

};

#include "const_iterator.hpp"

#endif