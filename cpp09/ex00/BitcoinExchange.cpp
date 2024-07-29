#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(std::string data)
{
	exchangeInfo = read_csv(data);
};

BitcoinExchange::~BitcoinExchange() {};

std::vector<std::pair<std::string, std::vector<int> > > read_csv(std::string filename)
{
	std::vector<std::pair<std::string, std::vector<int> > > result;

	// Create an input filestream
	std::ifstream myFile(filename.c_str());

	// Make sure the file is open
	if (!myFile.is_open())
		throw std::runtime_error("Could not open file");

	// Helper vars
	std::string line, colname;
	int val;

	// Read the column names
	if (myFile.good())
	{
		std::getline(myFile, line);

		std::stringstream ss(line);

		while (std::getline(ss, colname, ','))
		{
			std::pair<std::string, std::vector<int> > tempPair(colname, std::vector<int>());
			result.push_back(tempPair);
		}
	}

	// Read data, line by line
	while (std::getline(myFile, line))
	{
		std::stringstream ss(line);

		int colIdx = 0;

		// Extract each integer
		while (ss >> val)
		{
			result.at(colIdx).second.push_back(val);
			if (ss.peek() == ',')
				ss.ignore();
			colIdx++;
		}
	}
	myFile.close();

	return result;
}