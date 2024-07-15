#include "Form.hpp"

#include <string>

Form::Form() : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_exec(150) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int Form::getGradeToExec() const
{
	return _grade_to_exec;
}
const char* Form::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Grade too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << std::string(22, '-') << std::endl
	   << "Form name: " << f.getName() << std::endl
	   << "Signed: " << f.getSigned() << std::endl
	   << "Grade to sign: " << f.getGradeToSign() << std::endl
	   << "Grade to execute: " << f.getGradeToExec() << std::endl
	   << std::string(22, '-') << std::endl;
	return os;
}