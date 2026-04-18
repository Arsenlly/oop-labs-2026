#ifndef CCONST_ITERATOR_HPP__

#define CONST_ITERATOR_HPP__

#include "const_iterator.h"

template<typename T>
ConstIterator<T>::ConstIterator(const std::shared_ptr<typename List<T>::Node>& node)
{
    this->curr = node;
}

template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &it)
{

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
const T& ConstIterator<T>::operator*()
{
    return (this->curr).lock()->getValue();
}

template<typename T>
ConstIterator<T>::operator bool()
{
    return ((this->curr).lock() != nullptr);
}

template<typename T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &it)
{
    return (this->curr).lock() == (it.curr).lock();
}

template<typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &it)
{
    return (this->curr).lock() != (it.curr).lock();
}

#endif