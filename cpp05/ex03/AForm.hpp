#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _signed;
	int const _grade_to_sign;
	int const _grade_to_exec;
	std::string const _target;

protected:
	AForm();
	AForm(std::string name, int grade_to_sign, int grade_to_exec);
	AForm(std::string name, int grade_to_sign, int grade_to_exec, std::string target);

public:
	AForm(const AForm &obj);
	virtual ~AForm();

	AForm &operator=(const AForm &obj);
	std::string getName() const;
	std::string getTarget() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(Bureaucrat &b);

	void execute(Bureaucrat const &executor) const;
	virtual void executeBehaviour() const = 0;

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
	class NoSignatureException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif