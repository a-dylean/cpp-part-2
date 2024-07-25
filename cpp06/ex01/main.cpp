#include "Serializer.hpp"

int main()
{
	Data* data = new Data();
	
    data->value = 42;
	data->str = "Hello";

	std::cout << "Struct Data: " << std::endl << "Str: " << data->str << std::endl << "Value: " << data->value << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	Data* newPtr = Serializer::deserialize(ptr);

    std::cout << "newPtr: " << std::endl << "Str: " << newPtr->str << std::endl << "Value: " << newPtr->value << std::endl;

	std::cout << "Address of the Data object:   " << data << std::endl;
    std::cout << "Address of the newPtr object: " << newPtr << std::endl;

    delete data;

	return 0;
}