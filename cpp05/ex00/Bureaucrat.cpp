#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {};

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
};

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return _name;
};

int Bureaucrat::getGrade() const
{
	return _grade;
};

void Bureaucrat::increment()
{
	_grade--;
	if (_grade < 1)
		throw GradeTooLowException();
	else if (_grade > 150)
		throw GradeTooHighException();
};

void Bureaucrat::decrement()
{
	_grade++;
	if (_grade < 1)
		throw GradeTooLowException();
	else if (_grade > 150)
		throw GradeTooHighException();
}
const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Exception: Grade too high!");
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Exception: Grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}