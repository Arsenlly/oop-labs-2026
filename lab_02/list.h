#ifndef LIST_H__

#define LIST_H__

#include <initializer_list>
#include <memory>
#include <ranges>
#include <algorithm>

#include "concepts.h"
#include "base_container.h"
#include "iterator.h"
#include "const_iterator.h"
#include "list_exception.h"

template<ListType T>
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
        List(List<T>&& l) noexcept;

        template<Convertible<T> U>
        List(const List<U>& l);

        template<Convertible<T> U>
        List(List<U>&& l) noexcept;

        template<Convertible<T> U>
        List(std::initializer_list<U> l);

        template<ConvertibleContainer<T> C>
        explicit List(const C& cont);

        template<ConvertibleIterator<T> It, Sentinel<It> S>
        explicit List(const It& beg_it, const S& end_it);

        template<Convertible<T> U>
        List(const size_t size, const U *array);

    #pragma endregion

    #pragma region Destructor

    ~List() override;

    #pragma endregion

    #pragma region AssignOperators

    List<T> &operator=(const List<T>& l);
    List<T> &operator=(List<T>&& l) noexcept;

    template<Convertible<T> U>
    List<T> &operator=(const List<U>& l);

    template<Convertible<T> U>
    List<T> &operator=(List<U>&& l) noexcept;

    template<ConvertibleContainer<T> C>
    List<T> &operator=(const C& cont);

    template<Convertible<T> U>
    List<T> &operator=(std::initializer_list<U> l);

    #pragma endregion

    #pragma region Add

        template<Convertible<T> U>
        void push_back(const U& value);

        template<Convertible<T> U>
        void push_front(const U& value);

        template<Convertible<T> U>
        void insert_after(Iterator<T> &pos, const U& value);

    #pragma endregion

    #pragma region ReturnElements

        T& back() const;
        T& front() const;

    #pragma endregion    

    #pragma region CheckList

    template<Convertible<T> U>
    bool has(const U &value) const;

    virtual bool empty() const noexcept;
    virtual size_t size() const noexcept;

    #pragma endregion

    #pragma region RemoveElements

        T pop_back();
        T pop_front();
        void remove(const T& value);

        virtual void clear() noexcept;

    #pragma endregion

    #pragma region Operators

    List<T>& operator+=(const T& el);
    List<T>& operator+=(const List<T>& l);
    
    List<T> operator+(const T& el);
    List<T> operator+(const List<T>& l);

    bool operator==(const List<T>& l) const;

    operator bool() const noexcept;

    #pragma endregion

    #pragma region Iterators
        Iterator<T> begin() noexcept;
        Iterator<T> end() noexcept;

        ConstIterator<T> begin() const noexcept;
        ConstIterator<T> end() const noexcept;

        ConstIterator<T> cbegin() const noexcept;
        ConstIterator<T> cend() const noexcept;
    #pragma endregion

    protected:

    #pragma region ClassNode

        class Node
        {
            public:
                Node();
                Node(const Node& value) = delete;
                Node(Node&& value) = delete;
                Node(const T& value);

                ~Node() = default;

                std::shared_ptr<Node> getNext() const noexcept;
                void setNext(const std::shared_ptr<Node>& next) noexcept;

                T& getValue() noexcept;
                void setValue(const T& value) noexcept;

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