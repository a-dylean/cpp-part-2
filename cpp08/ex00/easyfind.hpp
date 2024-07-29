#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

class NotFound : public std::exception
{
public:
	virtual const char *what() const throw();
};

template <typename T>
void easyfind(T &container, int value)
{
	if (std::find(container.begin(), container.end(), value) == container.end())
	{
		throw NotFound();
	}
	else
	{
		std::cout << "Found " << *std::find(container.begin(), container.end(), value) << std::endl;
	}
}
