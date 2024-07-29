#pragma once

#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
private:
    unsigned int N;
    std::vector<int> integers;
    Span();

public:
    Span(unsigned int N);
    Span(Span const &obj);
    ~Span();

    Span &operator=(const Span &obj);

    void addNumber(int number);
    void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
    int shortestSpan();
    int longestSpan();

    std::vector<int> getIntegers();
};