#pragma once

# include <iostream>
#include <exception>
# include <string>
# include <cstdlib>

template< typename T >
class Array {
	private:
		T	*items;
		unsigned int len;

	public:
		Array<T>(): items(NULL), len(0) {
			std::cout << "Default constructor called, empty array of created" << std::endl;
		};
		
		Array<T>( unsigned int n ): items(new T[n]()), len(n) {
			std::cout << "Constructor with a parameter called, array of " << n << " elements created" << std::endl;
		};
		
		Array<T>(const Array& src) : items(new T[src.len]()), len(src.len) {
        for (unsigned int i = 0; i < len; ++i) {
            items[i] = src.items[i];
        }
    	}

		~Array<T>() {
			std::cout << "Destructor called" << std::endl;
			if (items != NULL)
				delete [] items;
		}

		Array<T> &operator=(const Array &src)
		{
			if (this != &src) {
            delete[] items;
            len = src.len;
            items = new T[len]();
            for (unsigned int i = 0; i < len; ++i) {
                items[i] = src.items[i];
            }
        }
        return *this;
		}

		T &operator[]( unsigned int index )
		{
			if (index >= len || !items) {
				throw Array<T>::OutOfBoundsException();
			}
			return (items[index]);
		}

		const T &operator[]( unsigned int index ) const
		{
			if (index >= len || !items) {
				throw Array<T>::OutOfBoundsException();
			}
			return (items[index]);
		}
		
		class	OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {
					return ("Index out of bounds");
				};
		};

		unsigned int size() const {
			return (len);
		}
	
};