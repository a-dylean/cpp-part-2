#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
};

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) {
	if (this != &obj)
		*this = obj;
}

Bureaucrat	&Bureaucrat::operator= (const Bureaucrat &obj) {
	if (this == &obj)
		return *this;
	_grade = obj._grade;
	return *this;
}

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
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
};

void Bureaucrat::decrement()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;

	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because his grade is too low" << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) {
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
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
    os << std::string(49, '-') << std::endl
	<< "BUREAUCRAT INFO: " << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl
	<< std::string(49, '-') ;
    return os;
}