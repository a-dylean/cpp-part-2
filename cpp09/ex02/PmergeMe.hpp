#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <typeinfo>
#include <deque>

typedef std::vector<int>::iterator iterator;

template <typename T>
void printArr(std::string str, T &arr)
{
    std::cout << str << ": ";
    for (iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void printTime(std::clock_t start, std::clock_t end, int argc, T &container)
{
    double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    std::string name = typeid(container).name();
    name.erase(0, 3);
    name.erase(name.size() - 8);
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << name << ":  " << duration << "ms\n";
}

void displayVecSort(int argc, char **argv);