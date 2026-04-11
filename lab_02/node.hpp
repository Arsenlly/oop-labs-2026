#ifndef NODE_HPP__

#define NODE_HPP__

#include "list.h"

#include <iostream>

template<typename T>
List<T>::Node::Node()
{
    this->next = nullptr;
}

template<typename T>
List<T>::Node::Node(const T& value)
{
    this->value = value;
    this->next = nullptr;
}

template <typename T>
void List<T>::Node::setValue(const T& value)
{
    this->value = value;
}

template <typename T>
void List<T>::Node::setNext(std::shared_ptr<Node>& node)
{
    next = node;
}

template <typename T>
T& List<T>::Node::getValue()
{
    return value;
}

#endif