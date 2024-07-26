#include "Span.hpp"

Span::Span() : N(0), integers(0) {};

Span::Span(unsigned int N): N(N) {
    integers.reserve(N);
};

Span::Span(Span const &obj)
{
    if (this != &obj)
        *this = obj;
}

Span::~Span() {};

Span &Span::operator=(const Span &obj)
{
    if (this == &obj)
        return *this;
    N = obj.N;
    integers = obj.integers;
    return *this;
}

void Span::addNumber(int number) {
        if (integers.size() >= N) {
            throw std::out_of_range("Cannot add more numbers, the span is full.");
        }
        integers.push_back(number);
    }

int Span::shortestSpan() {
        if (integers.size() < 2) {
            throw std::logic_error("Not enough numbers to find a span.");
        }
        
        std::vector<int> sortedNumbers = integers;
        std::sort(sortedNumbers.begin(), sortedNumbers.end());

        int shortest = longestSpan();
        for (size_t i = 1; i < sortedNumbers.size(); ++i) {
            int span = abs(sortedNumbers[i] - sortedNumbers[i - 1]);
            if (span < shortest) {
                shortest = span;
            }
        }
        return shortest;
    }

    int Span::longestSpan() {
        if (integers.size() < 2) {
            throw std::logic_error("Not enough numbers to find a span.");
        }

        int minNumber = *std::min_element(integers.begin(), integers.end());
        int maxNumber = *std::max_element(integers.begin(), integers.end());

        return maxNumber - minNumber;
    }

    //   void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    //     if (std::distance(begin, end) + numbers.size() > N) {
    //         throw std::out_of_range("Cannot add range, the span would exceed its capacity.");
    //     }
    //     numbers.insert(numbers.end(), begin, end);
    // }

    void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
        if (std::distance(begin, end) + integers.size() > N) {
            throw std::out_of_range("Cannot add range, the span would exceed its capacity.");
        }
        integers.insert(integers.end(), begin, end);
    }