#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> 

class BitcoinExchange
{
private:
	// std::map<double, float> exchangeInfo;
	std::vector<std::pair<std::string, std::vector<int> > > exchangeInfo;

public:
	BitcoinExchange();
	BitcoinExchange(std::string data);
	~BitcoinExchange();
};

std::vector<std::pair<std::string, std::vector<int> > > read_csv(std::string filename);