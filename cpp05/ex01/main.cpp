#include "Bureaucrat.hpp"
#include "Form.hpp"

void test(std::string name, int grade)
{
	static int i = 1;
	std::cout << std::endl << "TEST " << i <<std::endl << "NAME: " << name << " | GRADE: " << grade << std::endl;
	try
	{
		Form form = Form("Form", 100, 100); 
		std::cout << form;
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
	test("Bob", 100);
	// test("Sam", -10);
	// test("Alex", 155);
	// test("Bill", 1);
}