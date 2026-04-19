#ifndef CONCEPTS_H__

#define CONCEPTS_H__

#include <compare>
#include <concepts>

template<typename From, typename To>
concept Convertible = std::same_as<From, To> || std::convertible_to<From, To>;

template<typename C>
concept Container = 
    std::copy_constructible<C> &&
    std::move_constructible<C> &&
    std::destructible<C> &&
    requires(C c)
    {
        typename std::remove_reference_t<C>::value_type;
        typename std::remove_reference_t<C>::reference;
        typename std::remove_reference_t<C>::const_reference;
        typename std::remove_reference_t<C>::const_iterator;
        typename std::remove_reference_t<C>::difference_type;
        typename std::remove_reference_t<C>::size_type;
        {c.cbegin()} noexcept -> std::same_as<typename std::remove_reference_t<C>::const_iterator>;
        {c.cend()} noexcept -> std::same_as<typename std::remove_reference_t<C>::const_iterator>;
        {c.size()} noexcept -> std::same_as<typename std::remove_reference_t<C>::size_type>;
        {c.empty()} noexcept -> std::same_as<bool>;
    };

template<typename C>
concept IsList = std::same_as<List<typename C::value_type>, C>;

template<typename C, typename T>
concept ConvertibleContainer = 
    !IsList<C> && Container<C> && Convertible<typename std::remove_reference_t<C>::value_type, T>;

template<typename It, typename T>
concept ConvertibleIterator = std::input_iterator<It> && Convertible<typename It::value_type, T>;

template<typename S, typename It>
concept Sentinel = std::sentinel_for<S, It>;

#endif