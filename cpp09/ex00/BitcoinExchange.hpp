#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include <cmath>

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
	float calculateResult(std::string date, float valueStr);
	void printConversion();
	void printResult(std::string date, float valueStr);
};

std::map<std::string, float> parseFile(const std::string &filename);
bool isValidValue(const std::string &valueStr, float &value);
bool isValidDate(const std::string &date);