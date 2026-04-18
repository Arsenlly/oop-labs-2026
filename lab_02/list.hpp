#ifndef LIST_HPP__

#define LIST_HPP__

#include "list.h"

#include <iostream>

template<typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
}

template<typename T>
List<T>::List(const List<T>& l)
{
    for (const auto& el : l)
    {
        push_back(el);
    }

    // std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
}

template<typename T>
List<T>::List(const List<T>&& l)
{
    head = l.head;
    tail = l.tail;
    l.clean();
}

template<typename T>
template<Convertible<T> U>
List<T>::List(std::initializer_list<U> l)
{
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
}

template<typename T>
template<ConvertibleContainer<T> C>
List<T>::List(const C& cont)
{
    for (auto el : cont)
    {
        push_back(el);
    }
}

template<typename T>
template<typename I>
List<T>::List(const I& beg_it, const I& end_it)
{
    std::ranges::for_each(beg_it, end_it, [this](const T& el){push_back(el);});
}

template<typename T>
void List<T>::push_back(const T& value)
{
    std::shared_ptr<Node> new_node = std::make_shared<Node>(value);
    if(tail != nullptr)
        tail->setNext(new_node);
    tail = new_node;
    if(head == nullptr)
        head = tail;
    ++this->_size;
}

template<typename T>
void List<T>::push_front(const T& value)
{
    try
    {
        std::shared_ptr<Node> old_head = head;
        head = std::make_shared<Node>(value);
        head->setNext(old_head);
        if (tail == nullptr)
            tail = head;
        ++this->_size;
    }
    catch(std::bad_alloc &ex)
    {
        throw ListAllocateError(__FILE__, typeid(*this).name(), __LINE__, "Allocate error");
    }
    
}

template<typename T>
T& List<T>::back()
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");

    return tail->getValue();
}

template<typename T>
T& List<T>::front()
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");
    return head->getValue();
}

template<typename T>
T List<T>::pop_back()
{
    T value = tail->getValue();
    // TODO
    this->_size--;
    return value;
}

template<typename T>
T List<T>::pop_front()
{
    T value = head->getValue();
    head = head->getNext();
    this->_size--;
    return value;
}

template<typename T>
Iterator<T> List<T>::begin()
{
    return Iterator<T>(head);
}

template<typename T>
Iterator<T> List<T>::end()
{
    return Iterator<T>();
}

template<typename T>
ConstIterator<T> List<T>::begin() const
{
    return ConstIterator<T>(head);
}

template<typename T>
ConstIterator<T> List<T>::end() const
{
    return ConstIterator<T>();
}

template<typename T>
ConstIterator<T> List<T>::cbegin()
{
    return ConstIterator<T>(head);
}

template<typename T>
ConstIterator<T> List<T>::cend()
{
    return ConstIterator<T>();
}

template<typename T>
List<T>& List<T>::operator+=(const T& el)
{
    this->push_back(el);
    return *this;
}

template<typename T>
List<T>& List<T>::operator+=(const List<T>& l)
{
    for(auto el : l)
        this->push_back(el);
    return *this;
}

template<typename T>
List<T> List<T>::operator+(const T& el)
{
    List<T> res(*this);
    res.push_back(el);
    return res;
}

template<typename T>
List<T> List<T>::operator+(const List<T>& l)
{
    List<T> res(*this);
    for (auto el : l)
        res.push_back(el);
    return res;
}

template<typename T>
bool List<T>::operator==(const List<T>& l)
{
    return 0;
}

template<typename T>
bool List<T>::empty()
{
    return size() == 0;
}

template<typename T>
void List<T>::clear()
{
    head.reset();
    tail.reset();
    this->_size = 0;
}
    
template<typename T>
size_t List<T>::size()
{
    return this->_size;
}

#endif