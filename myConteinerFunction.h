#ifndef MYCONTEINERFUNCTION_H
#define MYCONTEINERFUNCTION_H

#include <iterator>
#include <string>
#include <algorithm>

template <typename T>
void NegateAll(T& c)
{
    for (auto it = std::begin(c); it != std::end(c); ++it)
    {
        *it = -(*it);
    }
}

std::string operator-(const std::string &str);

template <typename T>
void absSort(T& cont)
{
    std::sort(std::begin(cont), std::end(cont),
        [](int r, int l) {return std::abs(r) < std::abs(l); });
}

template <typename F, typename S>
auto SumCont(const F& f, const S& s)
{
    size_t max_size = std::max(std::size(f), std::size(s));
    std::vector<decltype((*std::begin(f)) + (*std::begin(s)))> res(max_size);
    std::copy(std::begin(f), std::end(f), std::begin(res));
    std::transform(std::begin(s), std::end(s), std::begin(res), std::begin(res),
        [](auto l, auto r) {return l + r; });
    return res;
}

template <typename F, typename S, typename T, typename R>
void Separate1(const F& f, S& s, T& t, R lamb)
{
    for (auto it = std::begin(f); it != std::end(f); ++it)
    {
        if (lamb(*it))
        {
            s.insert(std::end(s), *it);
        }
        else
        {
            t.insert(std::end(t), *it);
        }
    }
}

#endif // MYCONTEINERFUNCTION_H
