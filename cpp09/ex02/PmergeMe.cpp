#include "PmergeMe.hpp"

bool debug_mode = true;

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
    std::vector<int> jacobsthal;
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
    jacobsthal = populateJacob(vec);
    printArr("Before: ", vec);
    runSort(vec, jacobsthal, argc);
    runSort(dec, jacobsthal, argc);
}
