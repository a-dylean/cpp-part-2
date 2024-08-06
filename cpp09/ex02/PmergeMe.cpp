#include "PmergeMe.hpp"

int strToInt(const std::string &str)
{
    std::istringstream ss(str);
    int ret;
    ss >> ret;
    return ret;
}
std::pair<size_t, size_t> makePairs(std::size_t n)
{
    if (n < 2)
    {
        throw std::invalid_argument("n must be greater than 1");
    }
    for (size_t i = 1; i < 33; i++)
    {
        if (n < SequenceSize[i])
            return std::make_pair(SequenceSize[i - 1], SequenceSize[i]);
    }
    throw std::out_of_range("n is too large to find a pair in SequenceSize array");
}

void displaySort(int argc, char **argv)
{
    std::vector<int> vec;
    std::clock_t startVec = std::clock();
    try
    {
        populate(vec, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    printArr("Before", vec);
    try
    {
        fordJohnsonSortVector(vec);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::clock_t endVec = std::clock();
    printArr("After", vec);
    
    std::deque<int> dec;
    std::clock_t startDec = std::clock();
    try 
    {
        populate(dec, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    try
    {
        fordJohnsonSortVector(dec);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::clock_t endDec = std::clock();
    printTime(startVec, endVec, argc, vec);
    printTime(startDec, endDec, argc, dec);
}