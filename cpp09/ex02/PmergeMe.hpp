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
#include <iomanip>

int strToInt(const std::string &str);

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
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << name << ":  " << std::fixed << std::setprecision(5) << duration << " ms" << std::endl;
}
template <typename T>
void populate(T &arr, int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        if (strToInt(argv[i]) < 1)
            throw std::invalid_argument("array contains negative number or 0");
        arr.push_back(strToInt(argv[i]));
    }
}
// template <typename T>
// void sortPair(T &arr, int i, int j)
// {
//     if (arr[i] > arr[j])
//         std::swap(arr[i], arr[j]);
// }
// template <typename T>
// void sortLastNumber(T &arr)
// {
//     int lastNumber = arr.back();
//     arr.pop_back();
//     size_t i;
//     for (i = 0; i < arr.size(); i++)
//     {
//         if (lastNumber < arr[i])
//         {
//             arr.insert(arr.begin() + i, lastNumber);
//             break;
//         }
//     }
//     if (i == (arr.size())) //remove ?
//         arr.push_back(lastNumber);
// }

void displaySort(int argc, char **argv);

template <typename Container>
void sortPair(Container &container, size_t index1, size_t index2) {
    if (container[index1] > container[index2]) {
        std::swap(container[index1], container[index2]);
    }
}

template <typename Container>
void recursiveSort(Container &container, size_t start, size_t end) {
    if (end - start <= 1) return;

    size_t mid = start + (end - start) / 2;
    recursiveSort(container, start, mid);
    recursiveSort(container, mid, end);

    // Merge the two halves using binary insertion
    Container merged;
    typename Container::iterator it1 = container.begin() + start;
    typename Container::iterator it2 = container.begin() + mid;

    while (it1 != container.begin() + mid && it2 != container.begin() + end) {
        if (*it1 < *it2) {
            merged.push_back(*it1++);
        } else {
            merged.push_back(*it2++);
        }
    }

    while (it1 != container.begin() + mid) {
        merged.push_back(*it1++);
    }

    while (it2 != container.begin() + end) {
        merged.push_back(*it2++);
    }

    std::copy(merged.begin(), merged.end(), container.begin() + start);
}

template <typename Container>
void sortVec(Container &container) {
    typedef typename Container::value_type ValueType;

    // Step 1: Pairwise comparison
    for (size_t i = 0; i < container.size() - 1; i += 2) {
        sortPair(container, i, i + 1);
    }

    // Step 2: Recursive sort
    recursiveSort(container, 0, container.size());

    // Step 3: Handle odd-sized container
    if (container.size() % 2 != 0) {
        ValueType lastNumber = container.back();
        container.pop_back();
        typename Container::iterator pos = std::lower_bound(container.begin(), container.end(), lastNumber);
        container.insert(pos, lastNumber);
    }
}