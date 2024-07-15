#include "Bureaucrat.hpp"

void test(std::string name, int grade)
{
	static int i = 1;
	std::cout << std::endl << "TEST " << i <<std::endl << "NAME: " << name << " | GRADE: " << grade << std::endl;
	try
	{
		Bureaucrat bob = Bureaucrat(name, grade);  // This might throw an exception
		std::cout << "Bureaucrat's name: " << bob.getName() << std::endl;
		std::cout << "Initial grade: " << bob.getGrade() << std::endl;
		bob.increment(); // This might throw an exception
		std::cout << "Grade after incrementing: " << bob.getGrade() << std::endl;
		bob.decrement(); // This might also throw an exception
		std::cout << "Grade after decrementing: " << bob.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	i++;
}

int main()
{
	test("Bob", 100);
	test("Sam", -10);
	test("Alex", 155);
	test("Bill", 1);
}