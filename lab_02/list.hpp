#ifndef LIST_HPP__

#define LIST_HPP__

#include "list.h"

#include <iostream>

#pragma region Constructors

template<ListType T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
}

template<ListType T>
template<Convertible<T> U>
List<T>::List(const List<U>& l)
{
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
}

template<ListType T>
template<Convertible<T> U>
List<T>::List(List<U>&& l)
{
    head = l.head;
    tail = l.tail;
    l.clear();
}

template<ListType T>
List<T>::List(const List<T>& l)
{
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
}

template<ListType T>
List<T>::List(List<T>&& l)
{
    head = l.head;
    tail = l.tail;
    l.clear();
}

template<ListType T>
template<Convertible<T> U>
List<T>::List(std::initializer_list<U> l)
{
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
}

template<ListType T>
template<ConvertibleContainer<T> C>
List<T>::List(const C& cont)
{
    std::ranges::for_each(cont, [this](const T& el){push_back(el);});
}

template<ListType T>
template<Convertible<T> U>
List<T>::List(const size_t size, const U *array)
{
    std::ranges::for_each(array, array + size, [this](const T& el){this->push_back(el);});
}

template<ListType T>
template<ConvertibleIterator<T> It, Sentinel<It> S>
List<T>::List(const It& beg_it, const S& end_it)
{
    std::ranges::for_each(beg_it, end_it, [this](const T& el){push_back(el);});
}

#pragma endregion

#pragma region AssignOperators

template<ListType T>
List<T> &List<T>::operator=(const List<T>& l)
{
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
    return *this;
}

template<ListType T>
List<T> &List<T>::operator=(List<T>&& l)
{
    head = l.head;
    tail = l.tail;
    l.clean();
    return *this;
}

template<ListType T>
template<ConvertibleContainer<T> C>
List<T> &List<T>::operator=(const C& cont)
{
    std::ranges::for_each(cont, [this](const T& el){push_back(el);});
    return *this;
}

template<ListType T>
template<Convertible<T> U>
List<T> &List<T>::operator=(std::initializer_list<U> l)
{
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
    return *this;
}

#pragma endregion

#pragma region Add

template<ListType T>
template<Convertible<T> U>
void List<T>::push_back(const U& value)
{
    std::shared_ptr<Node> new_node = std::make_shared<Node>(value);
    if(tail != nullptr)
        tail->setNext(new_node);
    tail = new_node;
    if(head == nullptr)
        head = tail;
    ++this->_size;
}

template<ListType T>
template<Convertible<T> U>
void List<T>::push_front(const U& value)
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

template<ListType T>
template<Convertible<T> U>
void List<T>::insert_after(Iterator<T> &pos, const U& value)
{
    try
    {
        std::shared_ptr<Node> new_node = std::make_shared<Node>(value);
        new_node->setNext(pos.getNode()->getNext());
        pos.getNode()->setNext(new_node);
        ++this->_size;
    }
    catch(std::bad_alloc &ex)
    {
        throw ListAllocateError(__FILE__, typeid(*this).name(), __LINE__, "Allocate error");
    }
}

#pragma endregion

#pragma region ReturnElements

template<ListType T>
T& List<T>::back()
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");

    return tail->getValue();
}

template<ListType T>
T& List<T>::front()
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");
    return head->getValue();
}

#pragma endregion

#pragma region Remove

template<ListType T>
T List<T>::pop_back()
{
    T value = tail->getValue();
    // TODO
    this->_size--;
    return value;
}

template<ListType T>
T List<T>::pop_front()
{
    T value = head->getValue();
    head = head->getNext();
    this->_size--;
    return value;
}

template<ListType T>
void List<T>::remove(const T& value)
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");
    
    std::shared_ptr<Node> prev = nullptr;
    std::shared_ptr<Node> cur = head;

    while(cur != nullptr)
    {
        if (cur->getValue() == value)
        {
            if (prev == nullptr)
            {
                head = cur->getNext();
            }
            else
            {
                prev->setNext(cur->getNext());
            }
            cur = cur->getNext();
            _size--;
        }
        else
        { 
            prev = cur;
            cur = cur->getNext();
        }
    }
}

#pragma endregion

#pragma region Iteartors

template<ListType T>
Iterator<T> List<T>::begin()
{
    return Iterator<T>(head);
}

template<ListType T>
Iterator<T> List<T>::end()
{
    return Iterator<T>();
}

template<ListType T>
ConstIterator<T> List<T>::begin() const
{
    return ConstIterator<T>(head);
}

template<ListType T>
ConstIterator<T> List<T>::end() const
{
    return ConstIterator<T>();
}

template<ListType T>
ConstIterator<T> List<T>::cbegin() const
{
    return ConstIterator<T>(head);
}

template<ListType T>
ConstIterator<T> List<T>::cend() const
{
    return ConstIterator<T>();
}

#pragma endregion

#pragma region CheckList

template<ListType T>
template<Convertible<T> U>
bool List<T>::has(const U &value) const
{
    return std::ranges::any_of(*this, [value](const T &el){return el == value;});
}

template<ListType T>
bool List<T>::empty()
{
    return size() == 0;
}

template<ListType T>
void List<T>::clear()
{
    head.reset();
    tail.reset();
    this->_size = 0;
}
    
template<ListType T>
size_t List<T>::size()
{
    return this->_size;
}

#pragma endregion

#pragma region Operators

template<ListType T>
List<T>& List<T>::operator+=(const T& el)
{
    this->push_back(el);
    return *this;
}

template<ListType T>
List<T>& List<T>::operator+=(const List<T>& l)
{
    for(auto el : l)
        this->push_back(el);
    return *this;
}

template<ListType T>
List<T> List<T>::operator+(const T& el)
{
    List<T> res(*this);
    res.push_back(el);
    return res;
}

template<ListType T>
List<T> List<T>::operator+(const List<T>& l)
{
    List<T> res(*this);
    for (auto el : l)
        res.push_back(el);
    return res;
}

template<ListType T>
bool List<T>::operator==(const List<T>& l)
{
    return 0;
}

template<ListType T>
List<T>::operator bool() const noexcept
{
    return _size != 0;
}

#pragma endregion

#endif