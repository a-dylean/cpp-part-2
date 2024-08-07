#include "PmergeMe.hpp"

bool debug_mode = false;

void checkInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string str(argv[i]);
        if (str.find_first_not_of("-0123456789") != str.npos)
            throw std::invalid_argument("invalid input: not a number");
        double value = strtod(argv[i], 0);
        if (value > INT_MAX || value < 1)
            throw std::invalid_argument("invalid input: not within INT range, negavite number or 0");
    }
};

void displaySort(int argc, char **argv)
{
    std::vector<int> vec;
    std::deque<int> dec;
    try
    {
        checkInput(argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    populateArr(vec, argc, argv);
    populateArr(dec, argc, argv);
    std::cout << "Before: " << std::flush;
    printArr(vec);
    try
    {
        std::clock_t startVec = std::clock();
        mergeInsertSort(vec);
        std::clock_t endVec = std::clock();
        std::cout << "After: " << std::flush;
        printArr(vec);
        printTime(startVec, endVec, argc, vec);
        std::clock_t startDec = std::clock();
        mergeInsertSort(dec);
        std::clock_t endDec = std::clock();
        std::cout << "After: " << std::flush;
        printArr(dec);
        printTime(startDec, endDec, argc, dec);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
}
