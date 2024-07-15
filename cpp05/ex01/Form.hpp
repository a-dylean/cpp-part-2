#pragma once

#include <iostream>

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
	~Form();
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

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
