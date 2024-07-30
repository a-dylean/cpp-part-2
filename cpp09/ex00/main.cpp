#include "BitcoinExchange.hpp"

int main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong input! Usage: ./btc [INPUT FILE]" << std::endl;
		return (1);
	}
	BitcoinExchange btc(argv[1]);
	return 0;
};