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
std::vector<int> populateJacobsthalNums(std::vector<int> &arr);
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
void printTime(std::clock_t start, std::clock_t end, int argc, C &arr)
{
    double duration = 1000000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::string name = typeid(arr).name();
    name.erase(0, 3);
    name.erase(name.size() - 8);
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << name << ":  " << std::fixed << std::setprecision(2) << duration << " us" << std::endl;
}

template <typename P>
void sortPairs(P &pairs, size_t i)
{
    if (i == pairs.size())
        return;
    for (size_t j = i + 1; j < pairs.size(); j++)
    {
        if (pairs[i].second > pairs[j].second)
            std::swap(pairs[i], pairs[j]);
    }
    sortPairs(pairs, i + 1);
}
template <typename C>
size_t getIndex(C &arr, int value)
{
    size_t i = 0;
    for (typename C::iterator it = arr.begin(); it != arr.end(); it++)
    {
        if (*it == value)
            return i;
        i++;
    }
    return i;
}

template <typename C>
void binarySearchInsertion(C &arr, size_t low, size_t high, int value)
{
    size_t mid = low + (high - low) / 2;
    if (low == high)
    {
        arr.insert(arr.begin() + mid, value);
        return;
    }
    if (value < arr[mid])
        binarySearchInsertion(arr, low, mid, value);
    else
        binarySearchInsertion(arr, mid + 1, high, value);
}

template <typename C, typename P>
void startbinarySearchInsertion(C &arr, P &pairs, size_t index)
{
    int value = pairs[index].first;
    size_t low = 0;
    size_t high = getIndex(arr, value);
    binarySearchInsertion(arr, low, high, value);
}

template<typename C, typename P>
void fjmi(C &arr, P &pairs, std::vector<int> jacobsthalNums)
{
    bool sorted = false;
    size_t jIndex = 1;
    size_t jPrev = jacobsthalNums[jIndex - 1];
    size_t group;
    while (!sorted)
    {
        if (debug_mode)
            std::cout << "Next jacobsthal number: " << jacobsthalNums[jIndex] << std::endl;
        group = jacobsthalNums[jIndex];
        if (group >= pairs.size() - 1)
        {
            group = pairs.size() - 1;
            sorted = true;
        }
        while (group > jPrev)
        {
            startbinarySearchInsertion(arr, pairs, group);
            if (debug_mode)
                printArr("\nCurrent container state:\n", arr);
            group--;
        }
        jPrev = jacobsthalNums[jIndex];
        jIndex++;
    }
};

template<typename P>
void swapInsidePairs(P &pairs, std::vector<std::pair<int, int> >::iterator it)
{
    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
}

template <typename C, typename P>
void createPairs(C &arr, P &pairs, int &unpaired)
{
    int a = 0;
    int b = 0;
    
    for (typename C::iterator it = arr.begin(); it != arr.end(); it++)
    {
        a = *it;
        it++;
        if (it == arr.end())
        {
            unpaired = a;
            break;
        }
        b = *it;
        pairs.push_back(std::make_pair(a, b));
    }
};

template <typename C>
void mergeInsertSort(C &arr, std::vector<int> jacobsthalNums)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<std::pair<int, int> >::iterator it;
    int unpaired = -1;
    // PAIRWISE COMPARISON
    // 1. Create array of pairs from the container
    createPairs(arr, pairs, unpaired);
    printPairs(pairs);
    // 2. Swap the elements of the pair if the first element is bigger than the second
    swapInsidePairs(pairs, it);
    printPairs(pairs);
    // RECURSIVE SORT AND REPUSHING VALUES TO THE CONTAINER
    // 3. Sort pairs recursively by their higher value in ascending sequence
    sortPairs(pairs, 0);
    printPairs(pairs);
    // 4. Add the (first) lowest pair element to the container
    arr.clear();
    arr.push_back(pairs.begin()->first);
    // 5. Add all (second) the bigger values of the pairs to the container
    for (it = pairs.begin(); it != pairs.end(); it++)
        arr.push_back(it->second);
    // 6. Add the unpaired element to the pairs so that it can be inserted back
    if (unpaired != -1)
    {
        pairs.push_back(std::make_pair(unpaired, 0));
        printPairs(pairs);
    }
    if (debug_mode)
        printArr("\nCurrent container state:\n", arr);
    // BINARY INSERTION
    // 7. Insert the rest (first) lower values to the container using binary inserion and Jacobsthal numbers
    // to select those which would require minimal possible range of comparisons
    fjmi(arr, pairs, jacobsthalNums);
};

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