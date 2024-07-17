#include "Bureaucrat.hpp"
#include "Form.hpp"

void testForm(std::string name, int grade_to_sign, int grade_to_exec, Bureaucrat &b)
{
	static int i = 1;
	std::cout << std::endl
			  << std::string(21, '*') << "Test #" << i << std::string(21, '*') << std::endl;
	std::cout << "NAME: " << name << " | REQUIRED GRADE: " << grade_to_sign << std::endl;
	try
	{
		Form form = Form(name, grade_to_sign, grade_to_exec);
		std::cout << form << std::endl;
		std::cout << b << std::endl;
		std::cout << "🚩 Result: " << std::endl;
		b.signForm(form);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	i++;
}

int main()
{
	Bureaucrat strongB = Bureaucrat("Bob", 5);
	Bureaucrat weakB = Bureaucrat("Sam", 100);
	testForm("Invalid Form", 0, 0, strongB);
	testForm("Basic Form", 100, 150, strongB);
	testForm("Special Form", 5, 5, weakB);
}