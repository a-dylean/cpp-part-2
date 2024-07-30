#include "BitcoinExchange.hpp"

int main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl << "Usage: ./btc [INPUT FILE]" << std::endl;
		return (1);
	}
	BitcoinExchange btc(argv[1]);
	btc.printConversion();
	return 0;
};