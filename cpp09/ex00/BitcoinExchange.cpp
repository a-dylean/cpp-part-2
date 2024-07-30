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
        if (line.empty())
            continue;
        double value = 0;
        try
        {
            checkInput(line, value);
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
        printResult(line.substr(0, 10), value);
    }

    infile.close();
}

void BitcoinExchange::printResult(std::string date, double value)
{
    std::map<std::string, double>::iterator it = exchangeInfo.lower_bound(date);
    if (exchangeInfo.find(date) == exchangeInfo.end())
    {
        if (it != exchangeInfo.begin())
            it--;
        double mult = (*it).second * value;
        std::cout << date << " => " << value << " = " << mult << std::endl;
    }
    else
    {
        it = exchangeInfo.find(date);
        double mult = (*it).second * value;
        std::cout << date << " => " << value << " = " << mult << std::endl;
    }
}
// changes checks for each line here
// + add separate printing finctions and validating functions
void BitcoinExchange::checkInput(std::string line, double &value)
{
    std::istringstream iss(line);
    std::string date;

    if (std::getline(iss, date, '|'))
    {
        if (line.size() < 14 || line.substr(0, 10) == "2009-01-01")
            throw BadInputException();

        if (line.substr(10, 3) != " | ")
            throw BadInputException();

        line = line.substr(13, line.size() - 13);
        char *end;
        value = strtod(line.c_str(), &end);
        if (*end)
            throw BadInputException();

        if (value <= 0)
            throw NegativeNumberException();

        if (value > +1000)
            throw NumberTooLargeException();
    }
    else
    {
        throw BadInputException();
    }
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