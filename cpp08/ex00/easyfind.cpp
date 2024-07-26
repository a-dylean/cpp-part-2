#include "easyfind.hpp"

const char *NotFound::what() const throw() {
	return "Not found";
}