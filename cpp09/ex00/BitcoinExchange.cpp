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

void BitcoinExchange::printConversion()
{
    std::ifstream infile(inputData.c_str());

    if (!infile)
    {
        std::cerr << "Unable to open file: " << inputData << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;
        // float value;

        if (std::getline(iss, date, '|'))
        {
            date.erase(date.find_last_not_of(" \n\r\t") + 1);
            date.erase(0, date.find_first_not_of(" \n\r\t"));

            if (std::getline(iss, valueStr))
            {
                valueStr.erase(valueStr.find_last_not_of(" \n\r\t") + 1);
                valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

                std::cout << "DATE: " << date << std::endl;
                std::cout << "VALUESTR: " << valueStr << std::endl;
            }
            else
            {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
        else
        {
            // if (line == "date | value")
            //     continue;
            std::cerr << "here" << line << std::endl;
        }
    }

    infile.close();
}

float BitcoinExchange::calculateResult(std::string date, float valueStr)
{
    std::map<std::string, float>::const_iterator it = exchangeInfo.find(date);
    if (it != exchangeInfo.end())
    {
        return (it->second * valueStr);
    }
    return 555;
}

void BitcoinExchange::printResult(std::string date, float valueStr)
{
    float result = calculateResult(date, valueStr);
    std::cout << date << " => " << valueStr << " = " << result << std::endl;
}