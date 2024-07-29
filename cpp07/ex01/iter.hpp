#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t len, F func)
{
    if (!arr || !func)
        return;
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}