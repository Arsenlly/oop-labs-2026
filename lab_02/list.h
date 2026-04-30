#ifndef LIST_H__

#define LIST_H__

#include <initializer_list>
#include <memory>
#include <ranges>
#include <algorithm>
#include <ostream>

#include "concepts.h"
#include "base_list.h"
#include "iterator.h"
#include "const_iterator.h"
#include "list_exception.h"

template<ListType T>
class List:public BaseList
{
    public:

    #pragma region Aliases

        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = Iterator<T>;
        using const_iterator = ConstIterator<T>;
        using size_type = std::size_t;
    
    #pragma endregion
    
    public:

    #pragma region Constructors

        List() noexcept;
        List(const List<value_type>& l);
        List(List<value_type>&& l) noexcept;

        template<Convertible<value_type> U>
        List(const List<U>& l);

        template<Convertible<value_type> U>
        List(List<U>&& l) noexcept;

        template<Convertible<value_type> U>
        List(std::initializer_list<U> l);

        template<ConvertibleContainer<value_type> C>
        explicit List(const C& cont);

        template<ConvertibleIterator<value_type> It, Sentinel<It> S>
        explicit List(const It& beg_it, const S& end_it);

        template<Convertible<value_type> U>
        List(const size_type size, const U *array);

        template<Convertible<value_type> U>
        List(const size_type n, const U& el);

        template<ConvertibleRange<value_type> R>
        explicit List(const R &range);

    #pragma endregion

    #pragma region Destructor

    ~List() override;

    #pragma endregion

    #pragma region Assign

    List<value_type> &operator=(const List<value_type>& l);
    List<value_type> &operator=(List<value_type>&& l) noexcept;

    template<Convertible<value_type> U>
    List<value_type> &operator=(const List<U>& l);

    template<Convertible<value_type> U>
    List<value_type> &operator=(List<U>&& l) noexcept;

    template<ConvertibleContainer<value_type> C>
    List<value_type> &operator=(const C& cont);

    template<Convertible<value_type> U>
    List<value_type> &operator=(std::initializer_list<U> l);

    template<ConvertibleRange<value_type> R>
    List<value_type> &operator=(const R &range);

    #pragma endregion

    #pragma region Add

        template<Convertible<value_type> U>
        void push_back(const U& value);

        template<Convertible<value_type> U>
        void push_front(const U& value);

        template<Convertible<value_type> U>
        void insert_after(iterator &pos, const U& value);

        template<Convertible<value_type> U>
        void insert_after(iterator &pos, const List<U> &l);

        template<ConvertibleContainer<value_type> C>
        void insert_after(iterator &pos, const C &cont);

        template<ConvertibleIterator<value_type> It, Sentinel<It> S>
        void insert_after(iterator &pos, const It& beg_it, const S& end_it);

        template<ConvertibleRange<value_type> R>
        void insert_after(iterator &pos, const R &range);

        template<Convertible<value_type> U>
        List<value_type>& operator+=(const U& el);

        template<Convertible<value_type> U>
        List<value_type>& operator+=(const List<U>& l);
    
        template<ConvertibleContainer<value_type> C>
        List<value_type>& operator+=(const C& cont);

        template<ConvertibleRange<value_type> R>
        List<value_type>& operator+=(const R& range);

    #pragma endregion

    #pragma region Megre

    template<Convertible<value_type> U>
    List<value_type> merge(const List<U>& l) const;

    template<ConvertibleContainer<value_type> C>
    List<value_type> merge(const C& cont) const;

    template<ConvertibleRange<value_type> R>
    List<value_type> merge(const R& range) const;

    template<ConvertibleContainer<value_type> C>
    List<value_type> operator+(const C& cont) const;

    template<Convertible<value_type> U>
    List<value_type> operator+(const U& el) const;
    
    template<Convertible<value_type> U>
    List<value_type> operator+(const List<U>& l) const;

    template<ConvertibleRange<value_type> R>
    List<value_type> operator+(const R& range) const;

    #pragma endregion

    #pragma region ReturnElements

        reference back();
        reference front();

    #pragma endregion    

    #pragma region CheckList

    template<Convertible<value_type> U>
    bool has(const U &value) const;

    virtual bool empty() const noexcept;
    virtual size_type size() const noexcept;

    operator bool() const noexcept;

    #pragma endregion

    #pragma region RemoveElements

        value_type pop_back();
        value_type pop_front();

        template<Convertible<T> U>
        requires EqualTo<T, U>
        void remove(const U &value);

        void remove_after(Iterator<value_type> &pos);

        virtual void clear() noexcept;

    #pragma endregion

    #pragma region Comparate

    template<Convertible<value_type> U>
    requires EqualTo<T, U>
    bool operator==(const List<U>& l) const;

    #pragma endregion

    #pragma region Iterators
        iterator begin() noexcept;
        iterator end() noexcept;

        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
    #pragma endregion

    protected:

    #pragma region ClassNode

        class Node
        {
            public:
                Node(const Node& value) = delete;
                Node(Node&& value) = delete;
                Node(const_reference value, std::shared_ptr<Node> next = nullptr);

                ~Node() = default;

                std::shared_ptr<Node> getNext() const noexcept;
                void setNext(const std::shared_ptr<Node>& next) noexcept;

                reference getValue() noexcept;
                void setValue(const_reference value) noexcept;

            private:
                value_type value;
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

#pragma region StreamOperator

template<ListType T>
std::ostream &operator<<(std::ostream &os, const List<T> &l);

#pragma endregion

#pragma region Merge

template<ListType T, Convertible<T> U>
requires (!std::same_as<U, List<T>>) 
List<T> operator+(const U& el, const List<T> &l);

template<ListType T, ConvertibleContainer<T> C>
List<T> operator+(const C& cont, const List<T> &l);

template<ListType T, ConvertibleRange<T> R>
List<T> operator+(const R& range, const List<T> &l);

#pragma endregion

#include "list.hpp"
#include "node.hpp"

#endif