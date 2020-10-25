#ifndef PRINTCONTEINER_H
#define PRINTCONTEINER_H

#include <iterator>
#include <iostream>

template <typename T>
void printConteiner(const T& cont)
{
    for (auto it = std::cbegin(cont); it != std::cend(cont); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

template <typename F, typename S>
std::ostream& operator<<(std::ostream& out, const std::pair <F, S>& p)
{
    out << p.first << ' ' << p.second;
    return out;
}

#endif // PRINTCONTEINER_H
