#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <concepts>

template<typename T>
concept NotAbstract = !std::is_abstract_v<T>;

template<typename Derived, typename Base>
concept Derivative = std::is_abstract_v<Base> && std::is_base_of_v<Base, Derived>;

template<typename T, typename... Args>
concept Constructible = requires(Args... args)
{
    T{args...};
};

#endif // CONCEPTS_H
