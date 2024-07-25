#pragma once

# include <iostream>
# include <string>
# include <cstdlib>

template< typename T >
class Array {

	public:
		Array(): size_val(0) {
			std::cout << "Constructor called, empty array created." << std::endl;
			this->array = new T[this->size_val];
		};
		
		Array( unsigned int a ): size_val(a) {
			std::cout << "Constructor called, array created." << std::endl;
			this->array = new T[this->size_val];
		};
		
		Array(const Array &src): size_val(src.size()) {
			std::cout << "Copy Constructor called" << std::endl;
			this->array = NULL;
			*this = src;
		}

		~Array() {
			std::cout << "Destructor called" << std::endl;
			if (this->array != NULL)
				delete [] this->array;
		}

		Array &operator=(const Array &src)
		{
			if (this->array != NULL)
				delete [] this->array;
			if (src.size() != 0) {
				this->size_val = src.size();
				this->array = new T[this->size_val];
				for (unsigned int i = 0; i < this->size(); i++)
					this->array[i] = src.array[i];
			}
			return (*this);
		}

		T &operator[]( unsigned int index )
		{
			if (index >= this->size_val || this->array == NULL) {
				throw Array<T>::OutOfBoundsException();
			}
			return (this->array[index]);
		}
		
		class	OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {
					return ("Index out of bounds.");
				};
		};

		unsigned int size() const {
			return (this->size_val);
		}

	private:
		T	*array;
		unsigned int size_val;
	
};