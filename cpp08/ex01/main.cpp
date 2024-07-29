#include "Span.hpp"

#include <ctime>
#include <cstdlib>

void subjectTest()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void customTest(int num)
{
    std::cout << "Test with " << num << " numbers:" << std::endl;
    try
    {
        Span sp(num);

        std::srand(std::time(0));
        std::vector<int> numbers;
        numbers.reserve(num);
        for (int i = 0; i < num; ++i)
        {
            numbers.push_back(std::rand() % 100);
        }
        sp.addRange(numbers.begin(), numbers.end());
        std::vector<int> integers = sp.getIntegers();
        for (int i = 0; i < num; ++i)
        {
            std::cout << integers[i] << std::endl;
        }
        std::vector<int>::iterator minIt = std::min_element(integers.begin(), integers.end());
        std::cout << "Min int: " << *minIt << std::endl;

        std::vector<int>::iterator maxIt = std::max_element(integers.begin(), integers.end());
        std::cout << "Max int: " << *maxIt << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // uncommenting two lines below will throw an exception
        // sp.addNumber(34);
        // sp.addRange(numbers.begin(), numbers.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Test from subject:" << std::endl;
    subjectTest();
    std::cout << std::string(30, '-') << std::endl;
    customTest(10);
    std::cout << std::string(30, '-') << std::endl;
    // customTest(15000);
    return 0;
}