#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

     try {
        Span sp(10);
        sp.addNumber(6);
        sp.addNumber(3);

         int moreNumbersArray[] = {17, 9, 11, 4, 18};
        std::vector<int> moreNumbers(moreNumbersArray, moreNumbersArray + 5);
        sp.addRange(moreNumbers.begin(), moreNumbers.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected output
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Expected output

        // Uncomment the line below to test the exception for adding numbers beyond capacity
        sp.addRange(moreNumbers.begin(), moreNumbers.end());

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}