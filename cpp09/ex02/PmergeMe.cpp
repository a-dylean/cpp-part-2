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
    for (size_t i = 1; i < 33; i++)
    {
        if (n < jacobsthalNum[i])
            return std::make_pair(jacobsthalNum[i - 1], jacobsthalNum[i]);
    }
    throw std::out_of_range("n is too large to find a pair in Jacobsthal numbers");
}

void displaySort(int argc, char **argv)
{
    std::vector<int> vec;
    std::clock_t startVec = std::clock();
    try
    {
        populateArr(vec, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    printArr("Before", vec);
    try
    {
        mergeInsertSort(vec);
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
        populateArr(dec, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    try
    {
        mergeInsertSort(dec);
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