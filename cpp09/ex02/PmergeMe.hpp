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

const std::size_t jacobsthalNum[33] = {
    0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
    10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101,
    2796203, 5592405, 11184811, 22369621, 44739243, 89478485,
    178956971, 357913941, 715827883, 1431655765};
typedef std::vector<int>::iterator iterator;
int strToInt(const std::string &str);
void displaySort(int argc, char **argv);
std::pair<size_t, size_t> makePairs(std::size_t n);

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
    double duration = 1000000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::string name = typeid(container).name();
    name.erase(0, 3);
    name.erase(name.size() - 8);
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << name << ":  " << std::fixed << std::setprecision(2) << duration << " us" << std::endl;
}

template <typename T>
void populateArr(T &arr, int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string str(argv[i]);
        if (str.find_first_not_of("-0123456789") != str.npos)
            throw std::invalid_argument("invalid input: not a number");
        double value = strtod(argv[i], 0);
        if (value > INT_MAX || value < 1)
            throw std::invalid_argument("invalid input: not within INT range, negavite number or 0");
        arr.push_back(strToInt(argv[i]));
    }
}

template <typename Container>
Container setJakobSeqV(size_t n)
{
    Container jSeq;
    std::pair<size_t, size_t> pair = makePairs(n);
    if (pair.first > pair.second)
    {
        std::swap(pair.first, pair.second);
    }

    for (size_t i = 0; i < pair.second; ++i)
    {
        jSeq.push_back(i);
    }
    return jSeq;
}

template <typename Container>
void mergeVector(Container &arr, int left, int mid, int right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    Container L(arr.begin() + left, arr.begin() + mid + 1);
    Container R(arr.begin() + mid + 1, arr.begin() + right + 1);

    Container jakobSeq = setJakobSeqV<Container>(n1 + n2);
    size_t idx = 0;
    size_t i = 0;
    size_t j = 0;
    size_t k = left; // Start merging from the original 'left' index

    while (i < n1 && j < n2)
    {
        size_t a = jakobSeq[idx++];
        size_t b = jakobSeq[idx++];

        for (size_t count = a; count <= b; ++count)
        {
            if (i < n1 && j < n2)
            {
                if (L[i] <= R[j])
                {
                    arr[k++] = L[i++];
                }
                else
                {
                    arr[k++] = R[j++];
                }
            }
            else if (i < n1)
            {
                arr[k++] = L[i++];
            }
            else if (j < n2)
            {
                arr[k++] = R[j++];
            }
        }
    }
    // Copy remaining elements of L and R if any
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}
template <typename Container>
void insertVector(Container &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        insertVector(arr, left, mid);
        insertVector(arr, mid + 1, right);
        mergeVector(arr, left, mid, right);
    }
}

template <typename Container>
void mergeInsertSort(Container &arr)
{
    if (arr.size() < 2)
        return;
    insertVector(arr, 0, arr.size() - 1);
}