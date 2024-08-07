#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <typeinfo>
#include <iomanip>
#include <climits>

extern bool debug_mode;
void checkInput(int argc, char **argv);
void displaySort(int argc, char **argv);

template <typename C>
void populateArr(C &arr, int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        arr.push_back(std::atoi(argv[i]));
    }
}

template <typename C>
void printArr(std::string str, C &arr)
{
    std::cout << str << std::flush;
    for (typename C::iterator it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename C>
void printTime(std::clock_t start, std::clock_t end, int argc, C &arr)
{
    double duration = 1000000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::string name = typeid(arr).name();
    name.erase(0, 3);
    name.erase(name.size() - 8);
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << name << ":  " << std::fixed << std::setprecision(2) << duration << " us" << std::endl;
}
// Recursive function to sort all the pairs by the lager element of the pair
template <typename P>
void sortPairs(P &pairs, size_t i)
{
    if (i == pairs.size())
        return;
    for (size_t j = i + 1; j < pairs.size(); j++)
    {
        if (pairs[i].second > pairs[j].second)
        {
            std::pair<int, int> tmp = pairs[i];
            pairs[i] = pairs[j];
            pairs[j] = tmp;
        }
    }
    sortPairs(pairs, i + 1);
}

template <typename P>
void printPairs(P &pairs)
{
    if (debug_mode)
    {
        std::cout << "\nPairs:\n"
                  << std::flush;
        int i = 0;
        for (typename P::iterator it = pairs.begin(); it != pairs.end(); it++)
            std::cout << "[" << i++ << "] " << "(" << it->first << "\t; " << it->second << ") " << std::endl;
    }
}

template <typename C>
void printContainer(C &arr)
{
    if (debug_mode)
    {
        std::cout << "\nContainer:\n";
        for (typename C::iterator it = arr.begin(); it != arr.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

// Recursive function to insert
template <typename C>
void binarySearchInsert(C &arr, size_t low, size_t high, int value)
{
    // Find mid value
    size_t mid = low + (high - low) / 2;
    if (low == high)
    {
        arr.insert(arr.begin() + mid, value);
        return;
    }
    if (value < arr[mid])
        binarySearchInsert(arr, low, mid, value);
    else
        binarySearchInsert(arr, mid + 1, high, value);
}

template <typename C>
size_t findIndex(C &arr, int value)
{
    size_t i = 0;
    for (typename C::iterator it = arr.begin(); it != arr.end(); it++)
    {
        if (*it == value)
            return i;
        i++;
    }
    // If not found return the last index
    return i;
}

template <typename C, typename P>
void startBinarySearchInsert(C &arr, P &pairs, size_t index)
{
    int value = pairs[index].first;
    size_t low = 0;
    size_t high = findIndex(arr, value);
    binarySearchInsert(arr, low, high, value);
}

template <typename C>
void mergeInsertSort(C &arr, std::vector<int> jacobsthalNums)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<std::pair<int, int> >::iterator it;
    // 1. Group by pairs
    int a = 0;
    int b = 0;
    long leftover = -1;
    for (typename C::iterator it = arr.begin(); it != arr.end(); it++)
    {
        a = *it;
        it++;
        if (it == arr.end())
        {
            leftover = a;
            break;
        }
        b = *it;
        pairs.push_back(std::make_pair(a, b));
    }
    printPairs(pairs);

    // 2. Sort the pairs in place
    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first > it->second)
        {
            std::swap(it->first, it->second);
        }
    }
    printPairs(pairs);

    // 3. Sort all the pairs by the lager element of the pair
    sortPairs(pairs, 0);
    printPairs(pairs);

    // 4. Add the lowest pair member to the container
    arr.clear();
    arr.push_back(pairs.begin()->first);

    // 5. Add the bigger (second) values of the pairs to the container
    for (it = pairs.begin(); it != pairs.end(); it++)
        arr.push_back(it->second);

    // 6. add the leftover to the pairs
    if (leftover != -1)
        pairs.push_back(std::make_pair(leftover, 0));
    printPairs(pairs);
    printContainer(arr);

    // insert the paried values in the container
    bool sorted = false;
    size_t jIndex = 1;
    size_t jPrev = jacobsthalNums[jIndex - 1];
    size_t k;
    while (!sorted)
    {
        if (debug_mode)
            std::cout << "Next jacobsthal number: " << jacobsthalNums[jIndex] << std::endl;
        // Insert the next paired number following the
        // Jaconsthal numberindex
        k = jacobsthalNums[jIndex];
        if (k >= pairs.size() - 1)
        {
            k = pairs.size() - 1;
            sorted = true;
        }
        // Insert backwards down to the previous jacobsthalNums number
        while (k > jPrev)
        {
            startBinarySearchInsert(arr, pairs, k);
            printContainer(arr);
            k--;
        }
        // Increment the jacobsthalNums index
        jPrev = jacobsthalNums[jIndex];
        jIndex++;
    }
};
// Populate the jacobsthalNums Sequence
template <typename C>
std::vector<int> populateJacob(C &arr)
{
    std::vector<int> jacobsthalNums;
    jacobsthalNums.push_back(0);
    jacobsthalNums.push_back(1);
    jacobsthalNums.push_back(3);
    for (int i = 3; i < static_cast<int>(arr.size()); i++)
        jacobsthalNums.push_back(jacobsthalNums[i - 1] + 2 * jacobsthalNums[i - 2]);
    if (debug_mode)
    {
        std::cout << "Jacobsthal numbers sequence:\t";
        for (std::vector<int>::iterator it = jacobsthalNums.begin(); it != jacobsthalNums.end(); it++)
            std::cout << *it << " ";
    }
    return jacobsthalNums;
}

template <typename C>
void runSort(C &arr, std::vector<int> jacobsthalNums, int argc)
{
    std::clock_t start = std::clock();
    mergeInsertSort(arr, jacobsthalNums);
    std::clock_t end = std::clock();
    if (typeid(arr) == typeid(std::vector<int>))
        printArr("After: ", arr);
    printTime(start, end, argc, arr);
}