#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class  ScalarConverter
{
    public:
        ScalarConverter(ScalarConverter const &obj);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &obj);
        static void		convert(std::string str);
};

#endif