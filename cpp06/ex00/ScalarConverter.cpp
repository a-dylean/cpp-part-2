#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

bool isChar(const std::string &str)
{
	return str.length() == 1 && !isdigit(str[0]);
}

bool isInt(const std::string &str)
{
	char *end;
	long val = strtol(str.c_str(), &end, 10);
	return *end == '\0' && val >= INT_MIN && val <= INT_MAX;
}

bool isFloat(const std::string &str)
{
	char *end;
	errno = 0;
	float val = strtof(str.c_str(), &end);
	return *end == 'f' && end[1] == '\0' && errno == 0 && val != HUGE_VALF && val != -HUGE_VALF;
}

bool isDouble(const std::string &str)
{
	char *end;
	errno = 0;
	double val = strtod(str.c_str(), &end);
	return *end == '\0' && errno == 0 && val != HUGE_VAL && val != -HUGE_VAL;
}

bool isInf(const std::string &str)
{
	return str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf";
}
num_type getType(const std::string &str)
{
	if (isChar(str))
		return CHAR;
	if (isInt(str))
		return INT;
	if (isFloat(str))
		return FLOAT;
	if (isDouble(str))
		return DOUBLE;
	if (isInf(str))
		return INF;
	return ERR;
}

void convertChar(const std::string &str)
{
	char c = str[0];
	if (!isprint(str[0]))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::flush;
	std::cout << static_cast<float>(c) << std::flush;
	if (static_cast<float>(c) == floor(static_cast<float>(c)))
		std::cout << ".0" << std::flush;
	std::cout << "f" << std::endl;
	std::cout << "double: " << std::flush;
	std::cout << static_cast<double>(c) << std::flush;
	if (static_cast<double>(c) == floor(static_cast<double>(c)))
		std::cout << ".0" << std::flush;
	std::cout << std::endl;
}

void convertInt(const std::string &str)
{
	int i = atoi(str.c_str());
	if (!isprint(static_cast<char>(i)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	if (i >= INT_MIN && i <= INT_MAX)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::flush;
	std::cout << static_cast<float>(i) << std::flush;
	if (static_cast<float>(i) == floor(static_cast<float>(i)))
		std::cout << ".0" << std::flush;
	std::cout << "f" << std::endl;
	std::cout << "double: " << std::flush;
	std::cout << static_cast<double>(i) << std::flush;
	if (static_cast<double>(i) == floor(static_cast<double>(i)))
		std::cout << ".0" << std::flush;
	std::cout << std::endl;
}

void convertFloat(const std::string &str)
{
	float f = strtof(str.c_str(), NULL);
	if (f >= CHAR_MIN && f <= CHAR_MAX && isprint(static_cast<char>(f)))
	{
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
	if (static_cast<int>(f) >= INT_MIN && static_cast<int>(f) <= INT_MAX)
	{
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << std::flush;
	std::cout << f << std::flush;
	if (f == floor(f))
		std::cout << ".0" << std::flush;
	std::cout << "f" << std::endl;
	std::cout << "double: " << std::flush;
	std::cout << static_cast<double>(f) << std::flush;
	if (static_cast<double>(f) == floor(static_cast<double>(f)))
		std::cout << ".0" << std::flush;
	std::cout << std::endl;
}

void convertDouble(const std::string &str)
{
	double d = strtod(str.c_str(), NULL);
	if (d >= CHAR_MIN && d <= CHAR_MAX && isprint(static_cast<char>(d)))
	{
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
	if (d >= INT_MIN && d <= INT_MAX)
	{
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << std::flush;
	std::cout << static_cast<float>(d) << std::flush;
	if (static_cast<float>(d) == floor(static_cast<float>(d)))
		std::cout << ".0" << std::flush;
	std::cout << "f" << std::endl;
	std::cout << "double: " << std::flush;
	std::cout << d << std::flush;
	if (d == floor(d))
		std::cout << ".0" << std::flush;
	std::cout << std::endl;
}

void convertInf(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str[0] == '-')
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
	}
}

void printError()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
void ScalarConverter::convert(const std::string &str)
{
	if (str.size() == 0)
	{
		std::cerr << "Invalid literal" << std::endl;
		return;
	}
	switch (getType(str))
	{
	case CHAR:
		convertChar(str);
		break;
	case INT:
		convertInt(str);
		break;
	case FLOAT:
		convertFloat(str);
		break;
	case DOUBLE:
		convertDouble(str);
		break;
	case INF:
		convertInf(str);
		break;
	default:
		printError();
	}
}