#pragma once

#include <exception>
#include <iostream>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
	Bureaucrat();

public:
	Bureaucrat(std::string const name, int grade);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what( void ) const throw();
	};
	
	class GradeTooLowException : public	std::exception
	{
		public:
			const char	*what( void ) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& b);

