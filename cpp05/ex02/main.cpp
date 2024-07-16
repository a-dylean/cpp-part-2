#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>

template<typename T>
void testForm(T &form, Bureaucrat &b, int i) 
{ 	
	std::cout << std::endl << std::string(21, '*') << "Test #" << i << std::string(21, '*') << std::endl;
	std::cout << b << std::endl;
	std::cout << form << std::endl;
	std::cout << "🚩 Result: " << std::endl;
    try {
		b.signForm(form);
    	b.executeForm(form);
        form.execute(b);
		std::cout << "Form successfully executed ✅" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } 
}

template<typename T>
void testFormWithoutSignature(T &form, Bureaucrat &b, int i) 
{ 
	std::cout << std::endl << std::string(21, '*') << "Test #" << i << std::string(21, '*') << std::endl;
	std::cout << b << std::endl;
	std::cout << form << std::endl;
	std::cout << "🚩 Result: " << std::endl;
    try {
		// b.signForm(form);
		b.executeForm(form);
        form.execute(b);
		std::cout << "Form successfully executed ✅" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } 
}

template<typename T>
void runTests(T &form, Bureaucrat &wb, Bureaucrat &sb)
{
	static int i = 1;
	testForm(form, wb, i);
	i++;
	testFormWithoutSignature(form, sb, i);
	i++;
	testForm(form, sb, i);
}
int	main() 
{
	try {
		Bureaucrat strongB = Bureaucrat("Bob", 5);
		Bureaucrat weakB = Bureaucrat("Sam", 150);
		std::cout << "SHRUBERRY TEST" << std::endl;
		ShrubberyCreationForm	form("Shrubbery");
		runTests(form, weakB, strongB);
		std::cout << std::endl << "ROBOTOMY TEST" << std::endl;
		RobotomyRequestForm form1("Robotomy");
		runTests(form1, weakB, strongB);
		std::cout << std::endl << "PRESIDENTIAL PARDON TEST" << std::endl;
		PresidentialPardonForm form2("Presidential Pardon");
		runTests(form2, weakB, strongB);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}