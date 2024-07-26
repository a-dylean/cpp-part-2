#include "easyfind.hpp"

#include <vector>
#include <list>

void testList()
{
std::list<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.push_back(i * 2);
    }

    std::cout << "List:" << std::endl;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n\nTrying to find values from 0 to 8 in the array..." << std::endl;
    for (int i = 0; i < 9; i++)
    {
        try
        {  
            std::cout << std::string(30, '-') << std::endl;
            std::cout << "Value: " << i << std::endl;
            std::cout << "Result: " << std::flush;
            easyfind(list, i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void testVector()
{
	std::vector<int> vector;

	for (int i = 0; i < 10; i++)
	{
		vector.push_back(i * 2);
	}
    std::cout << "Vector:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << "\n\nTrying to find values from 0 to 8 in the array..." << std::endl;
	for (int i = 0; i < 9; i++)
	{
		try
		{  
            std::cout << std::string(30, '-') << std::endl;
            std::cout << "Value: " << i << std::endl;
            std::cout << "Result: " << std::flush;
			easyfind(vector, i);
          
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}

int main(void)
{
	testList();
	std::cout << std::endl << std::string(30, '=') << std::endl << std::endl;
	testVector();
	return 0;
}