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

        template<Convertible<value_type> U>
        List<value_type>& operator+=(const U& el);

        template<Convertible<value_type> U>
        List<value_type>& operator+=(const List<U>& l);
    
        template<ConvertibleContainer<value_type> C>
        List<value_type>& operator+=(const C& cont);

    #pragma endregion

    #pragma region Megre

    template<Convertible<value_type> U>
    List<value_type> merge(const List<U>& l) const;

    template<ConvertibleContainer<value_type> C>
    List<value_type> merge(const C& cont) const;

    template<ConvertibleContainer<value_type> C>
    List<value_type> operator+(const C& cont) const;

    template<Convertible<value_type> U>
    List<value_type> operator+(const U& el) const;
    
    template<Convertible<value_type> U>
    List<value_type> operator+(const List<U>& l) const;

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
        void remove(const_reference value);

        void remove_after(Iterator<value_type> &pos);

        virtual void clear() noexcept;

    #pragma endregion

    #pragma region Comparate

    bool operator==(const List<value_type>& l) const;

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

#include "list.hpp"
#include "node.hpp"

#endif