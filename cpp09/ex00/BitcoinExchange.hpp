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
#include <stdlib.h>
#include <iomanip>

#define DATABASE "data.csv"

class BitcoinExchange
{
private:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &obj);
	BitcoinExchange &operator=(BitcoinExchange const &obj);
	std::map<std::string, double> exchangeInfo;
	std::string inputData;
	double calculateResult(std::string date, double value);
	void printResult(std::string date, double value, double result);
	void convert(std::string const &line);
public:
	BitcoinExchange(std::string const &data);
	~BitcoinExchange();
	void printConversion();

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
bool isValidDate(std::string date);