#ifndef ITERATOR_HPP__

#define ITERATOR_HPP__

#include "iterator.h"

#pragma region Constructors

template<typename T>
Iterator<T>::Iterator(const std::shared_ptr<typename List<T>::Node>& node)
{
    this->curr = node;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &it)
{
    this->curr = it.curr.lock();
}

template<typename T>
Iterator<T>::Iterator(Iterator<T> &&it)
{
    this->curr = it.curr();
    it.curr.reset();
}

#pragma endregion

#pragma region Operators

template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& it)
{
    this->curr = it.curr.lock();
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator=(Iterator<T>&& it)
{
    this->curr = it.curr.lock();
    it.curr.reset();
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    this->curr = (this->curr).lock()->getNext();
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++(int)
{
    ++(*this);
    return *this;
}

template<typename T>
T& Iterator<T>::operator*()
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return (this->curr).lock()->getValue();
}

template<typename T>
std::shared_ptr<T>& Iterator<T>::operator->()
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return &(operator*);
}

template<typename T>
Iterator<T>::operator bool() const noexcept
{
    return ((this->curr).lock() != nullptr);
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &it) const noexcept
{
    return this->curr.lock() == it.curr.lock();
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &it) const noexcept
{
    return (this->curr).lock() != (it.curr).lock();
}

#pragma endregion

#endif