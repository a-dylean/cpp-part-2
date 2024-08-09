#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        calculateRNP(argv[1]);
        return 0;
    }
    std::cout << "Invalid input! Usage: ./RNP [inverted Polish mathematical expression]" << std::endl;
    return 1;
}