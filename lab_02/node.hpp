#ifndef NODE_HPP__

#define NODE_HPP__

#include "list.h"

template<ListType T>
List<T>::Node::Node()
{
    next = nullptr;
}

template<ListType T>
List<T>::Node::Node(const Node& node)
{
    next = node.next;
    value = node.value;
}

template<ListType T>
List<T>::Node::Node(Node&& node)
{
    next = node.next;
    value = node.value;
}

template<ListType T>
List<T>::Node::Node(const T& value)
{
    next = nullptr;
    this->value = value;
}

template<ListType T>
std::shared_ptr<typename List<T>::Node> List<T>::Node::getNext()
{
    return next;
}

template<ListType T>
void List<T>::Node::setNext(std::shared_ptr<typename List<T>::Node>& next)
{
    this->next = next;
}

template<ListType T>
T& List<T>::Node::getValue()
{
    return value;
}

template<ListType T>
void List<T>::Node::setValue(const T& value)
{
    this->value = value;
}

#endif