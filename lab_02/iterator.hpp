#ifndef ITERATOR_HPP__

#define ITERATOR_HPP__

#include "iterator.h"

#pragma region Constructors

template<ListType T>
Iterator<T>::Iterator(const std::shared_ptr<typename List<T>::Node>& node)
{
    this->curr = node;
}

template<ListType T>
Iterator<T>::Iterator(const Iterator<T> &it)
{
    this->curr = it.curr.lock();
}

#pragma endregion

#pragma region Operators

template<ListType T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& it)
{
    this->curr = it.curr.lock();
    return *this;
}

template<ListType T>
Iterator<T>& Iterator<T>::operator++()
{
    this->curr = (this->curr).lock()->getNext();
    return *this;
}

template<ListType T>
Iterator<T>& Iterator<T>::operator++(int)
{
    ++(*this);
    return *this;
}

template<ListType T>
T& Iterator<T>::operator*() const
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return (this->curr).lock()->getValue();
}

template<ListType T>
std::shared_ptr<T>& Iterator<T>::operator->() const
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return &(operator*);
}

template<ListType T>
Iterator<T>::operator bool() const noexcept
{
    return ((this->curr).lock() != nullptr);
}

template<ListType T>
bool Iterator<T>::operator==(const Iterator<T> &it) const noexcept
{
    return this->curr.lock() == it.curr.lock();
}

template<ListType T>
bool Iterator<T>::operator!=(const Iterator<T> &it) const noexcept
{
    return (this->curr).lock() != (it.curr).lock();
}

#pragma endregion

template<ListType T>
std::shared_ptr<typename List<T>::Node> Iterator<T>::getNode()
{
    return this->curr.lock();
}

#endif