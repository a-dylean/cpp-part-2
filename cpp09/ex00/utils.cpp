#include "BitcoinExchange.hpp"

std::map<std::string, float> parseFile(const std::string& filename) 
{
    std::map<std::string, float> datamap;
    std::ifstream infile(filename.c_str());
    
    if (!infile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return datamap;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string date;
        float value;
        
        if (std::getline(iss, date, ',') && (iss >> value)) {
            datamap[date] = value;
        } 
        // else {
        //     std::cerr << "Error parsing line: " << line << std::endl;
        // }
    }
    
    infile.close();
    return datamap;
}
