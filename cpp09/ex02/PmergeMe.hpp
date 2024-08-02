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
template <typename T>
void sortPair(T &arr, int i, int j)
{
    if (arr[i] > arr[j])
        std::swap(arr[i], arr[j]);
}
template <typename T>
void sortLastNumber(T &arr)
{
    int lastNumber = arr.back();
    arr.pop_back();
    size_t i;
    for (i = 0; i < arr.size(); i++)
    {
        if (lastNumber < arr[i])
        {
            arr.insert(arr.begin() + i, lastNumber);
            break;
        }
    }
    if (i == (arr.size())) //remove ?
        arr.push_back(lastNumber);
}

void displaySort(int argc, char **argv);