#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
#include <iostream>

struct Data;

class Serializer {
  private:
		Serializer();
		Serializer(Serializer const &copy);
		~Serializer();
		Serializer &operator=(const Serializer &copy);  
  public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif