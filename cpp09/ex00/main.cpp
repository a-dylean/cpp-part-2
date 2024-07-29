#include "BitcoinExchange.hpp"

int main()
{
	try
	{
		BitcoinExchange("./data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

};