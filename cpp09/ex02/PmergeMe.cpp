#include "PmergeMe.hpp"

int strToInt(const std::string &str)
{
    std::istringstream ss(str);
    int ret;
    ss >> ret;
    return ret;
}

void populateVec(std::vector<int> &vec, int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        if (strToInt(argv[i]) < 0)
            throw std::invalid_argument("array contains negative number");
        vec.push_back(strToInt(argv[i]));
    }
}

void sortPair(std::vector<int>& vec, int i, int j)
{
	if (vec[i] > vec[j]) std::swap(vec[i], vec[j]);
}

void sortLastNumber(std::vector<int>& vec)
{
	int lastNumber = vec.back();
	vec.pop_back();
	size_t i;
	for (i = 0; i < vec.size(); i++)
	{
		if (lastNumber < vec[i])
		{
			vec.insert(vec.begin() + i, lastNumber);
			break;
		}
	}
	if (i == (vec.size()))
		vec.push_back(lastNumber);
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
void displayVecSort(int argc, char **argv)
{
    std::vector<int> vec;
    try
    {
        populateVec(vec, argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    printArr("Before", vec);
    std::clock_t start = std::clock();
    try
    {
        sortVec(vec);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::clock_t end = std::clock();
    printArr("After", vec);
    printTime(start, end, argc, vec);
}