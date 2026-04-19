#ifndef CCONST_ITERATOR_HPP__

#define CONST_ITERATOR_HPP__

#include "const_iterator.h"

#pragma region Constructors

template<typename T>
ConstIterator<T>::ConstIterator(const std::shared_ptr<typename List<T>::Node>& node)
{
    this->curr = node;
}

template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &it)
{
    this->curr = it.curr.lock();
}

template<typename T>
ConstIterator<T>::ConstIterator(ConstIterator<T> &&it)
{
    this->curr = it.curr;
    it.curr.reset();
}

#pragma endregion

#pragma region Operators

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator=(const ConstIterator<T>& it)
{
    this->curr = it.curr.lock();
    return *this;
}

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator=(ConstIterator<T>&& it)
{
    this->curr = it.curr.lock();
    it.curr.reset();
    return *this;
}

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
    this->curr = (this->curr).lock()->getNext();
    return *this;
}

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator++(int)
{
    ++(*this);
    return *this;
}

template<typename T>
const T& ConstIterator<T>::operator*() const
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return (this->curr).lock()->getValue();
}

template<typename T>
const std::shared_ptr<T>& ConstIterator<T>::operator->() const
{
    if (this->curr.expired())
        throw IteratorExpiredError(__FILE__, typeid(*this).name(), __LINE__, "Iterator expired");
    return &(operator*);
}

template<typename T>
ConstIterator<T>::operator bool() const noexcept
{
    return ((this->curr).lock() != nullptr);
}

template<typename T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &it) const noexcept
{
    return this->curr.lock() == it.curr.lock();
}

template<typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &it) const noexcept
{
    return (this->curr).lock() != (it.curr).lock();
}

#endif