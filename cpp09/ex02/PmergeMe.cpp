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

std::vector<int> populateJacobsthalNums(std::vector<int> &arr)
{
    std::vector<int> jacobsthalNums;
    jacobsthalNums.push_back(0);
    jacobsthalNums.push_back(1);
    jacobsthalNums.push_back(3);
    for (int i = 3; i < static_cast<int>(arr.size()); i++)
        jacobsthalNums.push_back(jacobsthalNums[i - 1] + 2 * jacobsthalNums[i - 2]);
    if (debug_mode)
    {
        printArr("Jacobsthal numbers sequence: ", jacobsthalNums);
    }
    return jacobsthalNums;
}
void displaySort(int argc, char **argv)
{
    std::vector<int> jacobsthalNums;
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
    jacobsthalNums = populateJacobsthalNums(vec);
    printArr("Before: ", vec);
    runSort(vec, jacobsthalNums, argc);
    runSort(dec, jacobsthalNums, argc);
}
