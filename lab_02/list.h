#ifndef LIST_H__

#define LIST_H__

#include <initializer_list>
#include <memory>
#include <ranges>
#include <algorithm>

#include "base_container.h"
#include "iterator.h"
#include "const_iterator.h"
#include "concepts.h"
#include "list_exception.h"

template<typename T>
class List:public BaseContainer
{
    public:

    #pragma region Aliases

        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = Iterator<T>;
        using const_iterator = ConstIterator<T>;
        using difference_type = std::ptrdiff_t;
        using size_type = std::size_t;
    
    #pragma endregion
    
    public:

    #pragma region Constructors

        List();
        List(const List<T>& l);
        List(List<T>&& l);

        template<Convertible<T> U>
        List(std::initializer_list<U> l);

        template<ConvertibleContainer<T> C>
        List(const C& cont);

        template<ConvertibleIterator<T> It, Sentinel<It> S>
        List(const It& beg_it, const S& end_it);

        template<Convertible<T> U>
        List(const size_t size, const U *array);

    #pragma endregion

    #pragma region Assign

    List<T> &operator=(const List<T>& l);
    List<T> &operator=(List<T>&& l);

    template<ConvertibleContainer<T> C>
    List<T> &operator=(const C& cont);

    template<Convertible<T> U>
    List<T> &operator=(std::initializer_list<U> l);

    #pragma endregion

    #pragma region Add

        void push_back(const T& value);
        void push_front(const T& value);

    #pragma endregion

    #pragma region ReturnElements

        T& back();
        T& front();

    #pragma endregion    

    #pragma region RemoveElements

        T pop_back();
        T pop_front();

    #pragma endregion

    #pragma region Operators

    List<T>& operator+=(const T& el);
    List<T>& operator+=(const List<T>& l);
    
    List<T> operator+(const T& el);
    List<T> operator+(const List<T>& l);

    bool operator==(const List<T>& l);

    #pragma endregion

    virtual bool empty();
    virtual void clear();
    virtual size_t size();

    #pragma region Iterators
        Iterator<T> begin();
        Iterator<T> end();

        ConstIterator<T> begin() const;
        ConstIterator<T> end() const;

        ConstIterator<T> cbegin() const;
        ConstIterator<T> cend() const;
    #pragma endregion

    protected:

    #pragma region ClassNode

        class Node
        {
            public:
                Node();
                Node(const Node& value);
                Node(Node&& value);
                Node(const T& value);

                std::shared_ptr<Node> getNext();
                void setNext(std::shared_ptr<Node>& next);

                T& getValue();
                void setValue(const T& value);

            private:
                T value;
                std::shared_ptr<Node> next;
        };

    #pragma endregion

    #pragma region Friends

        friend class BaseIterator<T>;
        friend class Iterator<T>;
        friend class ConstIterator<T>;

    #pragma endregion

    private:
        std::shared_ptr<Node> head;
        std::shared_ptr<Node> tail;
};

#include "list.hpp"
#include "node.hpp"

#endif