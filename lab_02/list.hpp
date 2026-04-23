#ifndef LIST_HPP__

#define LIST_HPP__

#include "list.h"

#include <iostream>

#pragma region Constructors

template<ListType T>
List<T>::List() noexcept
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
List<T>::List(List<U>&& l) noexcept
{
    head = l.head;
    tail = l.tail;
    _size = l.size();
    l.clear();
}

template<ListType T>
List<T>::List(const List<T>& l)
{
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
}

template<ListType T>
List<T>::List(List<T>&& l) noexcept
{
    head = l.head;
    tail = l.tail;
    _size = l.size();
    l.clear();
}

template<ListType T>
template<Convertible<T> U>
List<T>::List(std::initializer_list<U> l)
{
    std::ranges::for_each(l, [this](const U& el){this->push_back(el);});
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

#pragma region Destructor

template<ListType T>
List<T>::~List()
{
    clear();
}

#pragma endregion

#pragma region AssignOperators

template<ListType T>
List<T> &List<T>::operator=(const List<T>& l)
{
    clear();
    std::ranges::for_each(l, [this](const T& el){this->push_back(el);});
    return *this;
}

template<ListType T>
List<T> &List<T>::operator=(List<T>&& l) noexcept
{
    clear();
    head = l.head;
    tail = l.tail;
    l.clean();
    return *this;
}

template<ListType T>
template<ConvertibleContainer<T> C>
List<T> &List<T>::operator=(const C& cont)
{
    clear();
    std::ranges::for_each(cont, [this](const T& el){push_back(el);});
    return *this;
}

template<ListType T>
template<Convertible<T> U>
List<T> &List<T>::operator=(std::initializer_list<U> l)
{
    clear();
    std::ranges::for_each(l, [this](const U& el){this->push_back(el);});
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

template<ListType T>
template<Convertible<T> U>
void List<T>::insert_after(Iterator<T> &pos, const List<U> &l)
{
    for(const auto& el : l)
    {
        insert_after(pos, el);
        pos++;
    }
}

template<ListType T>
template<ConvertibleContainer<T> C>
void List<T>::insert_after(Iterator<T> &pos, const C &cont)
{
    for(const auto& el : cont)
    {
        insert_after(pos, el);
        pos++;
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

#pragma region RemoveElements

template<ListType T>
T List<T>::pop_back()
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");

    T value = tail->getValue();

    std::shared_ptr<Node> prev = nullptr;
    std::shared_ptr<Node> cur = head;

    for(;cur != tail;prev = cur, cur = cur->getNext());

    if (prev == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        prev->setNext(nullptr);
    }

    this->_size--;
    return value;
}

template<ListType T>
T List<T>::pop_front()
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");

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

template<ListType T>
void List<T>::clear() noexcept
{
    head.reset();
    tail.reset();
    this->_size = 0;
}

template<ListType T>
void List<T>::remove_after(Iterator<T> &pos)
{
    if (empty())
        throw ListIsEmptyError(__FILE__, typeid(*this).name(), __LINE__, "List is empty");
    
    if (pos.getNode()->getNext() != nullptr)
    {
        pos.getNode()->setNext(pos.getNode()->getNext()->getNext());
        _size--;
    }
}

#pragma endregion

#pragma region Iteartors

template<ListType T>
Iterator<T> List<T>::begin() noexcept
{
    return Iterator<T>(head);
}

template<ListType T>
Iterator<T> List<T>::end() noexcept
{
    return Iterator<T>();
}

template<ListType T>
ConstIterator<T> List<T>::begin() const noexcept
{
    return ConstIterator<T>(head);
}

template<ListType T>
ConstIterator<T> List<T>::end() const noexcept
{
    return ConstIterator<T>();
}

template<ListType T>
ConstIterator<T> List<T>::cbegin() const noexcept
{
    return ConstIterator<T>(head);
}

template<ListType T>
ConstIterator<T> List<T>::cend() const noexcept
{
    return ConstIterator<T>();
}

#pragma endregion

#pragma region CheckList

template<ListType T>
template<Convertible<T> U>
bool List<T>::has(const U &value) const
{
    return std::ranges::any_of(*this, [&value](const T &el){return el == value;});
}

template<ListType T>
bool List<T>::empty() const noexcept
{
    return size() == 0;
}
    
template<ListType T>
size_t List<T>::size() const noexcept
{
    return this->_size;
}

#pragma endregion

#pragma region Operators

template<ListType T>
template<Convertible<T> U>
List<T>& List<T>::operator+=(const U& el)
{
    this->push_back(el);
    return *this;
}

template<ListType T>
template<Convertible<T> U>
List<T>& List<T>::operator+=(const List<U>& l)
{
    for(auto el : l)
        this->push_back(el);
    return *this;
}

template<ListType T>
template<ConvertibleContainer<T> C>
List<T>& List<T>::operator+=(const C& cont)
{
    for(auto el : cont)
        this->push_back(el);
    return *this;
}

template<ListType T>
template<ConvertibleContainer<T> C>
List<T> List<T>::operator+(const C& cont) const
{
    List<T> res(*this);
    for (auto el : cont)
        res.push_back(el);
    return res;
}

template<ListType T>
template<Convertible<T> U>
List<T> List<T>::operator+(const U& el) const
{
    List<T> res(*this);
    res.push_back(el);
    return res;
}

template<ListType T>
template<Convertible<T> U>
List<T> List<T>::operator+(const List<U>& l) const
{
    List<T> res(*this);
    for (auto el : l)
        res.push_back(el);
    return res;
}

template<ListType T>
bool List<T>::operator==(const List<T>& l) const
{
    if (_size != l.size())
    {
        return false;
    }
    else
    {
        auto it_beg_this = cbegin();
        auto it_end_this = cend();
        auto it_beg_l = l.cbegin();
        for(;it_beg_this != it_end_this;it_beg_l++, it_beg_this++)
        {
            if (*it_beg_l != *it_beg_this)
                return false;
        }
    }
    return true;
}

template<ListType T>
List<T>::operator bool() const noexcept
{
    return _size != 0;
}

#pragma endregion

#pragma region StreamOperator

template<ListType T>
std::ostream &operator<<(std::ostream &os, const List<T> &l)
{
    os << '[';

    bool first_flag = true;
    for(const auto &el : l)
    {
        if (!first_flag)
            os << ", ";
        os << el;
        first_flag = false;
    }

    os << ']';
    return os;
}

#pragma endregion

#endif