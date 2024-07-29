#include "MutantStack.hpp"
#include <list>

void subjectTest()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void listTest()
{
    std::list<int> list;

    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}
void methodsTest()
{
    std::list<int> list;

    list.push_back(5);
    list.push_back(17);
    list.pop_back();
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::reverse_iterator rit = list.rbegin();
    std::list<int>::reverse_iterator rite = list.rend();
    std::cout << "Reversed list:" << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.pop();
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::reverse_iterator mrit = mstack.rbegin();
    MutantStack<int>::reverse_iterator mrite = mstack.rend();
    std::cout << "Reversed mstack: " << std::endl;
    while (mrit != mrite)
    {
        std::cout << *mrit << std::endl;
        ++mrit;
    }

    std::cout << ".empty(): " << mstack.empty() << std::endl;

    MutantStack<int> s;
    std::cout << ".empty(): " << s.empty() << std::endl;
}

int main()
{
    std::cout << "Test from subject:" << std::endl;
    subjectTest();
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "Test with list container: " << std::endl;
    listTest();
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "Test for reverse iterators and empty member function:" << std::endl;
    methodsTest();
    return 0;
}
