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

void checkInput(int argc, char **argv);
void printArr(char **argv);
void displaySort(int argc, char **argv);
extern bool _print;
template <typename ContainerMain>
void print_after(ContainerMain &main_chain)
{
    for (typename ContainerMain::iterator it = main_chain.begin(); it != main_chain.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printTime(std::clock_t start, std::clock_t end, int argc, T &container)
{
    double duration = 1000000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::string name = typeid(container).name();
    name.erase(0, 3);
    name.erase(name.size() - 20);
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << name << ":  " << std::fixed << std::setprecision(2) << duration << " us" << std::endl;
}
// Recursive function to sort all the pairs by the lager element of the pair
template <typename P>
void sortPairs(P &p, size_t i)
{
    if (i == p.size())
        return;
    for (size_t j = i + 1; j < p.size(); j++)
    {
        if (p[i].second > p[j].second)
        {
            std::pair<int, int> tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
        }
    }
    sortPairs(p, i + 1);
}

template <typename P>
void printPairs(P &p)
{
    if (_print)
    {
        std::cout << "\nPairs:\n";
        for (typename P::iterator it = p.begin(); it != p.end(); it++)
            std::cout << "(" << it->first << "\t| " << it->second << ") " << std::endl;
    }
}

template <typename C>
void printContainer(C &c)
{
    if (_print)
    {
        std::cout << "\nContainer:\n";
        for (typename C::iterator it = c.begin(); it != c.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

// Recursive function to insert
template <typename C>
void binarySearchInsert(C &c, size_t low, size_t high, int value)
{
    // Find mid value
    size_t mid = low + (high - low) / 2;
    if (low == high)
    {
        c.insert(c.begin() + mid, value);
        return;
    }
    if (value < c[mid])
        binarySearchInsert(c, low, mid, value);
    else
        binarySearchInsert(c, mid + 1, high, value);
}

template <typename C>
size_t findIndex(C &c, int value)
{
    size_t i = 0;
    for (typename C::iterator it = c.begin(); it != c.end(); it++)
    {
        if (*it == value)
            return i;
        i++;
    }
    // If not found return the last index
    return i;
}

template <typename C, typename P>
void startBinarySearchInsert(C &c, P &p, size_t k)
{
    int value = p[k].first;
    size_t low = 0;
    size_t high = findIndex(c, value);
    binarySearchInsert(c, low, high, value);
}

template <typename C, typename P>
void sortContainer(C &c, P &p, std::vector<int> jacobsthal)
{
    // 1. Group by pairs
    unsigned int a = 0;
    unsigned int b = 0;
    long leftover = -1;
    for (typename C::iterator it = c.begin(); it != c.end(); it++)
    {
        a = *it;
        it++;
        if (it == c.end())
        {
            leftover = a;
            break;
        }
        b = *it;
        p.push_back(std::make_pair(a, b));
    }
    printPairs(p);

    // 2. Sort the pairs in place
    for (typename P::iterator it = p.begin(); it != p.end(); it++)
    {
        if (it->first > it->second)
        {
            unsigned int tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
    }
    printPairs(p);

    // 3. Sort all the pairs by the lager element of the pair
    sortPairs(p, 0);
    printPairs(p);

    // 4. Add the lowest pair member to the container
    c.clear();
    c.push_back(p.begin()->first);

    // 5. Add the bigger (second) values of the pairs to the container
    for (typename P::iterator it = p.begin(); it != p.end(); it++)
        c.push_back(it->second);

    // 6. add the leftover to the pairs
    if (leftover != -1)
        p.push_back(std::make_pair(leftover, 0));
    printPairs(p);
    printContainer(c);

    // insert the paried values in the container
    bool done = false;
    size_t jIndex = 1;
    size_t jPrev = jacobsthal[jIndex - 1];
    size_t k;
    while (!done)
    {
        if (_print)
            std::cout << "Next Jacobsthal number: " << jacobsthal[jIndex] << "\n";
        // Insert the next paired number following the
        // Jaconsthal numberindex
        k = jacobsthal[jIndex];
        if (k >= p.size() - 1)
        {
            k = p.size() - 1;
            done = true;
        }
        // Insert backwards down to the previous Jacobsthal number
        while (k > jPrev)
        {
            startBinarySearchInsert(c, p, k);
            printContainer(c);
            k--;
        }

        // Increment the Jacobsthal index
        jPrev = jacobsthal[jIndex];
        jIndex++;
    }
};

template <typename ContainerMain>
std::vector<int> populateJacob(ContainerMain &main_chain)
{
    // Populate the Jacobsthal Sequence
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    for (int i = 3; i < static_cast<int>(main_chain.size()); i++)
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    if (_print)
    {
        std::cout << "Jacobsthal Sequence:\t";
        for (std::vector<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++)
            std::cout << *it << " ";
    }
    return jacobsthal;
}

template <typename ContainerMain>
void mergeInsertSort(ContainerMain &main_chain, int argc, char **argv)
{
    std::vector<int> jacobsthal;
    // std::vector<int> v;
    std::vector<std::pair<int, int> > pv;
    for (int i = 1; i < argc; i++)
    {
        main_chain.push_back(std::atoi(argv[i]));
    }
    jacobsthal = populateJacob(main_chain);
    sortContainer(main_chain, pv, jacobsthal);
    // create_pairs(&arr, argv, &additional_value);
    // sort_pairs(&arr);
    // mergeSort<ContainerPairs>(arr.begin(), arr.end(), 0);
    // init_main_chain(&main_chain, arr);
    // insert_into_main_chain(arr, &main_chain, additional_value);
    std::cout << "After: " << std::flush;
    print_after(main_chain);
}