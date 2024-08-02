#include "PmergeMe.hpp"

int strToInt(const std::string &str)
{
    std::istringstream ss(str);
    int ret;
    ss >> ret;
    return ret;
}

void sortVec(std::vector<int> &vec)
{
    int lastNumber;
	bool odd = false;
	for (size_t i = 0; i < vec.size() - 1; i += 2)
		sortPair(vec, i, i + 1);
	if (vec.size() % 2 != 0)
	{
		lastNumber = vec.back();
		vec.pop_back();
		odd = true;
	}
	std::vector<int> firstPart;
	std::vector<int> secondPart;
	for (size_t i = 0; i != vec.size(); i += 2)
	{
		firstPart.push_back(vec[i]);
		secondPart.push_back(vec[i + 1]);
	}
	std::vector<int> firstPartSorted;
	for (size_t i = 0; i < firstPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (firstPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, firstPart[i]);
	}
	for (size_t i = 0; i < secondPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (secondPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, secondPart[i]);
	}
	if (odd == true)
	{
		odd = false;
		firstPartSorted.push_back(lastNumber);
		sortLastNumber(firstPartSorted);
	}
	vec.clear();
	vec = firstPartSorted;
}

void sortDec(std::deque<int> &dec)
{
    int lastNumber;
	bool odd = false;
	for (size_t i = 0; i < dec.size() - 1; i += 2)
		sortPair(dec, i, i + 1);
	if (dec.size() % 2 != 0)
	{
		lastNumber = dec.back();
		dec.pop_back();
		odd = true;
	}
	std::deque<int> firstPart;
	std::deque<int> secondPart;
	for (size_t i = 0; i != dec.size(); i += 2)
	{
		firstPart.push_back(dec[i]);
		secondPart.push_back(dec[i + 1]);
	}
	std::deque<int> firstPartSorted;
	for (size_t i = 0; i < firstPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (firstPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, firstPart[i]);
	}
	for (size_t i = 0; i < secondPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (secondPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, secondPart[i]);
	}
	if (odd == true)
	{
		odd = false;
		firstPartSorted.push_back(lastNumber);
		sortLastNumber(firstPartSorted);
	}
	dec.clear();
	dec = firstPartSorted;
}
void displaySort(int argc, char **argv)
{
    std::vector<int> vec;
    std::clock_t startVec = std::clock();
    try
    {
        populate(vec, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    printArr("Before", vec);
    try
    {
        sortVec(vec);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::clock_t endVec = std::clock();
    printArr("After", vec);
    
    std::deque<int> dec;
    std::clock_t startDec = std::clock();
    try 
    {
        populate(dec, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    try
    {
        sortDec(dec);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::clock_t endDec = std::clock();
    printTime(startVec, endVec, argc, vec);
    printTime(startDec, endDec, argc, dec);
}