#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &obj);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &obj);

	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(AForm &f);
	void executeForm(AForm const &form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif