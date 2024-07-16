#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_exec(150) {}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec, std::string target) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _target(target)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(AForm const &obj): _name(obj._name), _grade_to_sign(obj._grade_to_sign), _grade_to_exec(obj._grade_to_exec), _target(obj._target) {
	if (this != &obj)
		*this = obj;
}

AForm	&AForm::operator= (const AForm &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

std::string AForm::getTarget() const
{
	return _target;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _grade_to_sign;
}

int AForm::getGradeToExec() const
{
	return _grade_to_exec;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (_signed)
		return ;
	if (b.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (!_signed)
		throw AForm::NoSignatureException();
	if (executor.getGrade() > _grade_to_exec)
		throw AForm::GradeTooLowException();
	executeBehaviour();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Grade too low!");
}

const char *AForm:: NoSignatureException::what(void) const throw()
{
	return ("Exception: No signature!");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << std::string(49, '-') << std::endl
	<< "FORM INFO:" << std::endl
	<< std::string(49, '-') << std::endl
	   << "Form name: " << f.getName() << std::endl
	   << "Signed: " << f.getSigned() << std::endl
	   << "Grade to sign: " << f.getGradeToSign() << std::endl
	   << "Grade to execute: " << f.getGradeToExec() << std::endl
	   << std::string(49, '-') ;
	return os;
}