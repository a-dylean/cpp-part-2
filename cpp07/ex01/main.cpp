#include "iter.hpp"

template <typename T>
void printElement(const T &element)
{
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element)
{
    ++element;
}

int main()
{
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray:    ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incremented intArray: ";
    iter(intArray, intArraySize, incrementElement<int>);
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original doubleArray: ";
    iter(doubleArray, doubleArraySize, printElement<double>);
    std::cout << std::endl;
    std::cout << "Incremented intArray: ";
    iter(doubleArray, doubleArraySize, incrementElement<double>);
    iter(doubleArray, doubleArraySize, printElement<double>);

    std::cout << std::endl;

    // Test with an array of strings
    std::string stringArray[] = {"one", "two", "three", "four", "five"};
    int stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Original stringArray: ";
    iter(stringArray, stringArraySize, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}