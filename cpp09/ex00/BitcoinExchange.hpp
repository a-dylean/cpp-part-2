#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <exception>

#define DATABASE "data.csv"

class BitcoinExchange
{
private:
	std::map<std::string, double> exchangeInfo;
	std::string inputData;
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &inputData);
	BitcoinExchange &operator=(BitcoinExchange const &obj);

public:
	BitcoinExchange(std::string const &data);
	~BitcoinExchange();
	void printConversion();
	void printResult(std::string date, double value);
	void checkInput(std::string line, double &value);
	class BadInputException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class NegativeNumberException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class NumberTooLargeException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

std::map<std::string, double> parseFile(const std::string &filename);
bool isValidValue(const std::string &valueStr, float &value);
bool isValidDate(const std::string &date);