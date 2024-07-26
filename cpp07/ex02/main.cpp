#include "Array.hpp"

int main()
{
    try {
        std::cout << "Testing creation of empty array..." << std::endl;
        Array<int> emptyArray; // Default constructor

        std::cout << "\nTesting creation of array with specific size..." << std::endl;
        Array<int> intArray(5); // Parameterized constructor

        std::cout << "\nTesting copy constructor..." << std::endl;
        Array<int> copiedArray(intArray); // Copy constructor

        std::cout << "\nTesting assignment operator..." << std::endl;
        Array<int> assignedArray;
        assignedArray = intArray; // Assignment operator

        std::cout << "\nTesting element access and modification..." << std::endl;
        std::cout << "intArray before modification: ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        //modification
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 2;
        }
        std::cout << "\nintArray after modification:  ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "copiedArray: ";
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "assignedArray: ";
        for (unsigned int i = 0; i < assignedArray.size(); ++i) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\nTesting out of bounds access..." << std::endl;
       try {
            std::cout << intArray[10] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::cout << intArray[-5] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::cout << emptyArray[0] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::cout << copiedArray[10] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\nDestructors:" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}