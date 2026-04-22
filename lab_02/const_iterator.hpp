#ifndef CCONST_ITERATOR_HPP__

#define CONST_ITERATOR_HPP__

#include "const_iterator.h"

#pragma region Constructors

template<ListType T>
ConstIterator<T>::ConstIterator(const std::shared_ptr<typename List<T>::Node>& node)
{
    this->curr = node;
}

template<ListType T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &it)
{
    this->curr = it.curr.lock();
}

#pragma endregion

#pragma region Operators

template<ListType T>
ConstIterator<T>& ConstIterator<T>::operator=(const ConstIterator<T>& it)
{
    this->curr = it.curr.lock();
    return *this;
}

template<ListType T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
    this->curr = (this->curr).lock()->getNext();
    return *this;
}

template<ListType T>
ConstIterator<T>& ConstIterator<T>::operator++(int)
{
    ++(*this);
    return *this;
}

template<ListType T>
const T& ConstIterator<T>::operator*() const
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return (this->curr).lock()->getValue();
}

template<ListType T>
const std::shared_ptr<T>& ConstIterator<T>::operator->() const
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return &(operator*);
}

template<ListType T>
ConstIterator<T>::operator bool() const noexcept
{
    return ((this->curr).lock() != nullptr);
}

template<ListType T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &it) const noexcept
{
    return this->curr.lock() == it.curr.lock();
}

template<ListType T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &it) const noexcept
{
    return (this->curr).lock() != (it.curr).lock();
}

template<ListType T>
std::shared_ptr<const typename List<T>::Node> ConstIterator<T>::getNode() const
{
    return this->curr.lock();
}

#endif