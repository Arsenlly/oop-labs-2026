#ifndef LIST_HPP__

#define LIST_HPP__

#include "list.h"

#include <iostream>

// Конструктор
template <typename T>
List<T>::List()
{
    head = nullptr;
}

// Конструктор копирования
template <typename T>
List<T>::List(const List<T>& l)
{
}

// Конструктор переноса
template <typename T>
List<T>::List(List<T>&& l)
{
    clear();
    head = l.head;
    l.clear();
    std::cout << "a\n";
}

template <typename T>
List<T>::List(std::initializer_list<T> l)
{
    for (T el : l)
    {
        push_back(el);
    }
}

// Деструктор
template <typename T>
List<T>::~List()
{
    head.reset();
}

// Оператор копирования
template <typename T>
List<T>& List<T>::operator=(const List<T>& l)
{

}

// Оператор переноса
template <typename T>
List<T>& List<T>::operator=(const List<T>&& l)
{
    head = l.head;
    l.clear();
    return *this;
}


// Очистка
template <typename T>
void List<T>::clear()
{
    head.reset();
}   

// Добавление
template <typename T>
void List<T>::push_front(const T& el)
{
    auto old_head = head;
    head = std::make_shared<Node>(el);
    head->setNext(old_head);
}

template <typename T>
void List<T>::push_back(const T& el)
{
}

// Удаление
template <typename T>
T& List<T>::pop_front()
{
    
}

template <typename T>
T& List<T>::pop_back()
{
}

// Получение первого и последнего
template <typename T>
T& List<T>::front()
{
    return head->getValue();
}

template <typename T>
T& List<T>::back()
{

}

template <typename T>
bool List<T>::is_empty()
{
    if (head == nullptr)
        return true;
    return false;
}

#endif