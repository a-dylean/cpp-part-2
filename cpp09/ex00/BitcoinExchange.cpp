#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
};

BitcoinExchange::BitcoinExchange(std::string const &data)
{
    inputData = data;
    exchangeInfo = parseFile(DATABASE);
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
        if (line.empty() || line == "date | value")
            continue;
        try
        {
            convert(line);
        }
        catch (BadInputException &e)
        {
            std::cerr << e.what() << line << std::endl;
            continue;
        }
        catch (NegativeNumberException &e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        catch (NumberTooLargeException &e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
    }
    infile.close();
}

void BitcoinExchange::convert(const std::string &line)
{
    std::size_t separator = line.find(" | ");
    if (separator == std::string::npos)
    {
        throw BadInputException();
    }
    std::string date = line.substr(0, separator);
    std::string valueStr = line.substr(separator + 3);
    if (!isValidDate(date))
    {
        throw BadInputException();
    }
    double value = std::atof(valueStr.c_str());
    if (value < 0)
    {
        throw NegativeNumberException();
    }
    else if (value > 1000)
    {
        throw NumberTooLargeException();
    }
    printResult(date, value, calculateResult(date, value));
}
double BitcoinExchange::calculateResult(std::string date, double value)
{
    std::map<std::string, double>::iterator it = exchangeInfo.lower_bound(date);
    if (exchangeInfo.find(date) == exchangeInfo.end())
    {
        if (it != exchangeInfo.begin())
            it--;
    }
    else
    {
        it = exchangeInfo.find(date);
    }
    double mult = (*it).second * value;
    return mult;
}

void BitcoinExchange::printResult(std::string date, double value, double result)
{
    std::cout << std::fixed << std::setprecision(2) << date << " => " << value << " = " << result << std::endl;
}

const char *BitcoinExchange::BadInputException::what(void) const throw()
{
    return ("Error: bad input = > ");
}

const char *BitcoinExchange::NegativeNumberException::what(void) const throw()
{
    return ("Error: not a positive number.");
}

const char *BitcoinExchange::NumberTooLargeException::what(void) const throw()
{
    return ("Error: too large a number.");
}
