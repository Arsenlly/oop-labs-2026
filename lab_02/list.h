#ifndef LIST_H__

#define LIST_H__

#include <memory>
#include <ranges>
#include <initializer_list>

#include "base_container.h"

template <typename T>
class List final: public BaseContainer
{
    public:

        // Конструкторы
        List();
        List(const List& l);
        List(List&& l);
        List(std::initializer_list<T> l);
        
        // Деструктор
        ~List();

        // Очистка
        void clear();

        // Добавление
        void push_front(const T& el);
        void push_back(const T& el);

        // Удаление
        T& pop_front();
        T& pop_back();

        // Получение первого и последнего
        T& front();
        T& back();

        // Проверка на пустоту
        bool is_empty();


        List<T>& operator=(const List<T>& l);
        List<T>& operator=(const List<T>&& l);

    protected:
        class Node
        {
            public:
                Node();
                Node(const T& value);

                void setValue(const T& value);
                void setNext(std::shared_ptr<Node>& node);
                T& getValue();



            private:
                T value;
                std::shared_ptr<Node> next;
        };

    private:
        std::shared_ptr<Node> head;
};

#include "list.hpp"
#include "node.hpp"

#endif