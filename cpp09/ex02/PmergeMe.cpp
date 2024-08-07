#include "PmergeMe.hpp"

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

void printArr(char** argv)
{
    int i = 1;
    while (argv[i])
	{
        std::string input = argv[i];
	    std::cout << input << " ";
        i++;
    }
    std::cout << std::endl;
};

// bool custom_cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
//     return a.first < b.first;
// };


void displaySort(int argc, char **argv)
{
    std::vector<int> main_chain;
    try
    {
        checkInput(argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::cout << "Before: " << std::flush;
    printArr(argv);
    // std::clock_t startVec = std::clock();
    try
    {
        mergeInsertSort(main_chain, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    // std::clock_t endVec = std::clock();
    std::cout << "After: " << std::flush;
    print_after(main_chain);

    // std::deque<int> main_chain_dec;
    // std::clock_t startDec = std::clock();
    // try
    // {
    //     mergeInsertSort(dec, main_chain_dec, argv, additional_value);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << "Error: " << e.what() << std::endl;
    //     return;
    // }
    // std::clock_t endDec = std::clock();
    // std::cout << "After: " << std::flush;
    // print_after(main_chain_dec);
    // printTime(startVec, endVec, argc, main_chain);
    // printTime(startDec, endDec, argc, dec);
}

