#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <sstream>

enum num_type {
    ERR,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
	PSEUDO,
};

class  ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter& operator=(const ScalarConverter &copy);
        ~ScalarConverter();

    public:
        static void convert(const std::string &str);
};

#endif