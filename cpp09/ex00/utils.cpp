#include "BitcoinExchange.hpp"

std::map<std::string, double> parseFile(const std::string &filename)
{
    std::map<std::string, double> datamap;
    std::ifstream infile(filename.c_str());

    if (!infile)
    {
        std::cerr << "Error: could not open file." << filename << std::endl;
        return datamap;
    }
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string date;
        double value;
        if (std::getline(iss, date, ',') && (iss >> value))
        {
            datamap[date] = value;
        }
    }
    infile.close();
    return datamap;
}

bool isValidDate(std::string date)
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < static_cast<int>(date.size()); ++i)
    {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            return false;
    }
    // int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    // || year < 2009
    if (month < 1 || month > 12 || day < 1 || day > 31 )
        return false;
    return true;
}
