#pragma once
#include <iostream>
#include <string>

template <typename T>
bool CorrectPool(T var, T left, T right)
{
    return var >= left && var <= right;
}

template <typename T>
T Proverochka(T left, T right)
{
    T var;
    while ((std::cin >> var).fail() || !CorrectPool(var, left, right))
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
    return var;
}