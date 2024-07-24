#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

ScalarConverter::~ScalarConverter()
{
}


ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return *this;
}

static num_type get_type(const std::string & str) 
{  
    int		dots = 0;
	size_t	i = 0;
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff") {
		return PSEUDO;
	}
    // if (str == "nan" || str == "+inf" || str == "-inf")
    //     return DOUBLE;
    // if (str == "nanf" || str == "+inff" || str == "-inff")
    //     return FLOAT;
    while (str[i]) {
		if (i == str.length() - 1 && dots == 1 && (str[i] == 'f' || str[i] == 'F'))
			return FLOAT;
		if (str[i] != '.' && !isdigit(str[i]))
			return ERR;
		if (str[i] == '.')
			dots++;
		i++;
	}
	if (dots == 1 && (str[str.length() - 1] != '.'))
		return DOUBLE;
	if (!dots)
		return INT;
    if (str.length() == 1 && (str[0] >= 32 && str[0] < 127)) {
		return CHAR;
	}    
	return ERR;
}

static bool	setValues
	(const std::string &str, char &c, int &n, float &f, double &d) {
	switch (get_type(str)) {
		case ERR:
			return false;
		case CHAR:
			c = str[0];
			n = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT:
			n = atoi(str.c_str());
			c = static_cast<char>(n);
			f = static_cast<float>(n);
			d = static_cast<double>(n);
			break;
		case FLOAT:
			f = atof(str.c_str());
			c = static_cast<char>(f);
			n = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = strtod(str.c_str(), NULL);
			c = static_cast<char>(d);
			n = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
        case PSEUDO:
            break;

	}
	return true;
}

static void displayChar(const char &c, const double &d) {
	std::cout << "char: ";
	if (d > CHAR_MAX || !isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void displayInt(const int &n, const double &d) {
	std::cout << "int: ";
	if (d > INT_MAX)
		std::cout << "Overflow occured" << std::endl;
	else
		std::cout << n << std::endl;
}

static void displayFloat(const float &f, const double &d) {
	std::cout << "float: ";
	if (d > MAXFLOAT)
		std::cout << "Overflow occured" << std::endl;
	else {
		std::cout << f;
		if ((int)(f - (int)f == 0)) // if fractional part is 0
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void displayDouble(const double &d) {
	std::cout << "double: ";
	std::cout << d;
	if ((int)(d - (int)d == 0)) // if fractional part is 0
		std::cout << ".0";
	std::cout << std::endl;
}

static void	displayValues
	(const char &c, const int &n, const float &f, const double &d) {
	displayChar(c, d);
	displayInt(n, d);
	displayFloat(f, d);
	displayDouble(d);
}

void ScalarConverter::convert(const std::string &str)
{
    std::cout << get_type(str) << std::endl;
    char	c = 0;
	int		n = 0;
	float	f = 0;
	double	d = 0;

	if (!setValues(str, c, n, f, d)) {
		std::cerr << "FORMAT ERROR" << std::endl;
		return;
	}
	displayValues(c, n, f, d);

}

