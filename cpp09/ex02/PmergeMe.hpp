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
#include <list>

const std::size_t jacobsthalNum[33] = {
    0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
    10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101,
    2796203, 5592405, 11184811, 22369621, 44739243, 89478485,
    178956971, 357913941, 715827883, 1431655765};
void checkInput(int argc, char **argv);
void printArr(char** argv);
void displaySort(int argc, char **argv);
bool custom_cmp(const std::pair<int, int> &a, const std::pair<int, int> &b);

template <typename ContainerMain>
void print_after(ContainerMain main_chain)
{
	for (typename ContainerMain::iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
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

// Do merge sort with recursive approach splitting the list in half each time and merging them back together
template <typename ContainerPairs>
void mergeSort(typename ContainerPairs::iterator start, typename ContainerPairs::iterator end, size_t size) {
    if (size == 0 && start != end)
        size = std::distance(start, end);
    if (size <= 1)
        return;

    size_t firstHalf = size / 2;
    size_t secondHalf = size - firstHalf;
    typename ContainerPairs::iterator center = start;
    // Move the iterator to the center of the list
    std::advance(center, firstHalf);

    mergeSort<ContainerPairs>(start, center, firstHalf);
    mergeSort<ContainerPairs>(center, end, secondHalf);
    std::inplace_merge(start, center, end, custom_cmp);
}

// Do a binary search to find the correct position within the slice of the main chain and insert the value
template <typename ContainerMain>
void binary_search_insertion(ContainerMain *main_chain, typename ContainerMain::iterator end, int val) {
    typename ContainerMain::iterator place_to_insert = std::lower_bound(main_chain->begin(), end, val);
    main_chain->insert(place_to_insert, val);

    /*
    // print main chain
    std::cout << "main chain with current value: " << val << ": "
              << "end_interator: " << *end << " place_to_insert: " << *(place_to_insert--) << std::endl;
    for (typename ContainerMain::iterator it = main_chain->begin(); it != main_chain->end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
    */
}

template <typename ContainerMain, typename ContainerPairs>
void insert_into_main_chain(ContainerPairs listy, ContainerMain *main_chain, int additional_value) {
    int jacobsthal_idx = 1;

    typename ContainerMain::iterator slice_delim_it;
    typename ContainerPairs::iterator pair_it;
    typename ContainerPairs::iterator last_jacob_it = listy.begin();

    while (jacobsthalNum[jacobsthal_idx] <= listy.size()) {
        pair_it = listy.begin();
        std::advance(pair_it, jacobsthalNum[jacobsthal_idx] - 1);
        last_jacob_it = pair_it;

        // how many pend elements have been inserted
        int insertion_counter = 0;
        while (jacobsthalNum[jacobsthal_idx] - insertion_counter > jacobsthalNum[jacobsthal_idx - 1]) {
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
            binary_search_insertion(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
            insertion_counter++;
        }
        jacobsthal_idx++;
    }

    // if the Jacobsthal number is larger than the size of the list, insert the remaining elements
    if (jacobsthalNum[jacobsthal_idx] != listy.size()) {
        pair_it = listy.end();
        if (pair_it != listy.begin())
            pair_it--;
        while (pair_it != last_jacob_it) {
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
            binary_search_insertion(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
        }
    }

    if (additional_value != -1) {
        binary_search_insertion(main_chain, main_chain->end(), additional_value);
    }
}

template <typename ContainerMain, typename ContainerPairs>
void init_main_chain(ContainerMain *main_chain, ContainerPairs listy) {
    for (typename ContainerPairs::iterator it = listy.begin(); it != listy.end(); ++it)
        main_chain->push_back(it->second);

    // the first number of pend can always be inserted as the first number in the main chain.
    // it's always smaller than it's paired number
    if (!listy.empty())
        main_chain->insert(main_chain->begin(), listy.begin()->first);
}


template <typename ContainerPairs>
void sort_pairs(ContainerPairs *listy) {
    for (typename ContainerPairs::iterator it = listy->begin(); it != listy->end(); ++it) {
        if (it->first > it->second) {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
}

template <typename ContainerPairs>
void create_pairs(ContainerPairs *listy, char **argv, int *additional_value) {
    int i = 1;

    while (argv[i]) {
        if (argv[i] && argv[i + 1]) {
            std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
            listy->push_back(pair_temp);
            i += 2;
        } else {
            *additional_value = std::atoi(argv[i]);
            i++;
        }
    }
}

template <typename ContainerPairs, typename ContainerMain>
void mergeInsertSort(ContainerPairs &arr, ContainerMain &main_chain, char **argv, int additional_value) {
    create_pairs(&arr, argv, &additional_value);
    sort_pairs(&arr);
    mergeSort<ContainerPairs>(arr.begin(), arr.end(), 0);
    init_main_chain(&main_chain, arr);
    insert_into_main_chain(arr, &main_chain, additional_value);
}