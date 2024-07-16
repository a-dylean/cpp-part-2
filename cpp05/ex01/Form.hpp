#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _signed;
	int const _grade_to_sign;
	int const _grade_to_exec;
public:
	Form();
	Form(std::string name, int grade_to_sign, int grade_to_exec);
	Form(Form const &obj);
	~Form();

	Form &operator=(const Form &obj);
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &os, const Form& f);

#endif