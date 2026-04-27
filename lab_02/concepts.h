#ifndef CONCEPTS_H__

#define CONCEPTS_H__

#include <compare>
#include <concepts>

template<typename T, typename U>
concept EqualTo = requires(T a, U b)
{
    {a == b} -> std::same_as<bool>;
    {a != b} -> std::same_as<bool>;
    {b == a} -> std::same_as<bool>;
    {b != a} -> std::same_as<bool>;
};

template<typename T>
concept Assignable = requires(T t1, T t2)
{
    {t1 = t2} -> std::same_as<T&>;
};

template<typename T>
concept ListType = Assignable<T>;

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

template<ListType T>
class List;

template<typename C>
concept IsList = ListType<typename C::value_type> && std::same_as<List<typename C::value_type>, C>;

template<typename C, typename T>
concept ConvertibleContainer = 
    !IsList<C> && Container<C> && Convertible<typename std::remove_reference_t<C>::value_type, T>;

template<typename It, typename T>
concept ConvertibleIterator = std::input_iterator<It> && Convertible<typename It::value_type, T>;

template<typename S, typename It>
concept Sentinel = std::sentinel_for<S, It>;

template<typename R, typename T>
concept ConvertibleRange = 
    !IsList<R> && std::ranges::input_range<R> && Convertible<std::ranges::range_value_t<R>, T> && !Container<R>;

#endif