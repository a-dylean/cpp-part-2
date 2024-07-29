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

    // additional tests
    test("21");
    test("2147483647");
    test("21474836472147483647");
    test("0.76986795674567689");
    test("hello");
    return (0);
}