#pragma once

#include <algorithm>

namespace eda {

template<typename T1, typename T2>
struct pair
{
    using first_type = T1;
    using second_type = T2;

    first_type first;
    second_type second;

    pair()
        : first()
        , second()
    {
    }

    pair(const first_type& f, const second_type& s)
        : first(f)
        , second(s)
    {
    }

    template<typename U1, typename U2>
    pair(U1&& f, U2&& s)
        : first(std::forward<U1>(f))
        , second(std::forward<U2>(s))
    {
    }

    pair(pair&& p)
        : first(std::move(p.first))
        , second(std::move(p.second))
    {
    }

    template<typename U1, typename U2>
    pair(pair<U1, U2>&& p)
        : first(std::move(p.first))
        , second(std::move(p.second))
    {
    }

    template<typename U, typename Arg0, typename... Args>
    pair(U&& x, Arg0&& arg0, Args&&... args)
        : first(std::forward<U>(x))
        , second(std::forward<Arg0>(arg0)
            , std::forward<Args>(args)...)
    {
    }

    pair& operator=(pair&& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
        return *this;
    }

    template<typename U1, typename U2>
    pair& operator=(pair<U1, U2>&& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
        return *this;
    }

    void swap(pair&& p)
    {
        std::swap(first, p.first);
        std::swap(second, p.second);
    }
};

/// @brief additional functionality for using this pair
template <typename T1, typename T2>
inline bool operator==(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    return p1.first == p2.first && p1.second == p2.second;
}

template <typename T1, typename T2>
inline bool operator!=(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    return !(p1 == p2);
}

template <typename T1, typename T2>
inline bool operator<(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    return (p1.first < p2.first) || (!(p1.second < p2.second) &&(p1.second < p2.second));
}

template <typename T1, typename T2>
void swap(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{
    p1.swap(p2);
}

template <typename T1, typename T2>
void swap(const pair<T1, T2>&& p1, const pair<T1, T2>&& p2)
{
    p1.swap(p2);
}

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 p1, T2 p2)
{
    return pair<T1, T2>(p1, p2);
}

}
