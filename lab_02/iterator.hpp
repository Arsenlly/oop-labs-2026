#ifndef ITERATOR_HPP__

#define ITERATOR_HPP__

#include "iterator.h"

template<typename T>
Iterator<T>::Iterator(const std::shared_ptr<typename List<T>::Node>& node)
{
    this->curr = node;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &it)
{

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
    return (this->curr).lock()->getValue();
}

template<typename T>
Iterator<T>::operator bool()
{
    return ((this->curr).lock() != nullptr);
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &it)
{
    return (this->curr).lock() == (it.curr).lock();
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &it)
{
    return (this->curr).lock() != (it.curr).lock();
}

#endif