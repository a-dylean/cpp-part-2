#include "ScalarConverter.hpp"

void test(const std::string &str)
{
    std::cout << "Literal: " << str << std::endl;
    std::cout << std::string(30, '-') << std::endl;
    ScalarConverter::convert(str);
    std::cout << std::string(30, '-') << std::endl;
    std::cout << std::endl;
}
int main()
{
    // tests from subject
    test("0");
    test("nan");
    test("42.0f");

    // user input tests
    while (1)
    {
        std::string input;
        std::cout << "Enter a literal: ";
        if (std::cin.eof())
           return(0);
        std::cin >> input;
        std::cout << std::string(30, '-') << std::endl;
        ScalarConverter::convert(input);
        std::cout << std::string(30, '-') << std::endl;
        std::cout << std::endl;
    }
    return (0);
}