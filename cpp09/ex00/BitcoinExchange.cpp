#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	
};

BitcoinExchange::BitcoinExchange(std::string const &data)
{
	inputData = data;
	exchangeInfo = parseFile(DATABASE);
	// for (std::map<std::string, float>::iterator it = exchangeInfo.begin(); it != exchangeInfo.end(); ++it) {
    // std::cout << "Date: " << it->first << ", Exchange Rate: " << it->second << std::endl;
	// }
	// std::cout << inputData << std::endl;
}

BitcoinExchange::~BitcoinExchange() {};