#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Invalid input! Usage: ./PmergeMe [array of positive integers to be sorted separated by spaces]" << std::endl;
        return (1);
    }
    displaySort(argc, argv);
}
