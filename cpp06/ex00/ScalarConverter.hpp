#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cctype>
#include <cfloat>
#include <climits>
#include <sstream>
#include <cerrno>
#include <cmath>

enum num_type {
    ERR,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
	INF,
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