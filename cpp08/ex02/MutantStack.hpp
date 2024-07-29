#pragma once

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack<T, Container> &obj) : std::stack<T, Container>(obj) {}
    ~MutantStack() {}
    MutantStack<T, Container> &operator=(const MutantStack<T, Container> &obj)
    {
        if (this != &obj)
        {
            std::stack<T, Container>::operator=(obj);
        }
        return *this;
    }

    typedef typename Container::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    typedef typename Container::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
};