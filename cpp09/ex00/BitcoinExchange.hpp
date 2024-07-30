#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream> 

#define DATABASE "data.csv"

class BitcoinExchange
{
private:
	std::map<std::string, float> exchangeInfo;
	std::string inputData;
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &inputData);
	BitcoinExchange &operator=(BitcoinExchange const &obj);
public:
	BitcoinExchange(std::string const &data);
	~BitcoinExchange();
};

std::map<std::string, float> parseFile(const std::string& filename);