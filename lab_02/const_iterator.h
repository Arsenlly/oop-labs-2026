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
        ConstIterator(const std::shared_ptr<typename List<T>::Node>& node);
        ConstIterator(const ConstIterator<T> &it);
        ConstIterator(ConstIterator<T> &&it);

    #pragma endregion

    ~ConstIterator() override = default;

    #pragma region Operators
        ConstIterator<T>& operator=(const ConstIterator<T>& it);
        ConstIterator<T>& operator=(ConstIterator<T>&& it);

        ConstIterator<T>& operator++();
        ConstIterator<T>& operator++(int);

        const T& operator*() const;
        
        const std::shared_ptr<T>& operator->() const;
        
        operator bool() const noexcept;
        
        bool operator==(const ConstIterator<T> &it) const noexcept;
        bool operator!=(const ConstIterator<T> &it) const noexcept;

    #pragma endregion
};

#include "const_iterator.hpp"

#endif