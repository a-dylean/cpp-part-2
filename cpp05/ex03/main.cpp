#include "AForm.hpp"
#include "Intern.hpp"

int	main() 
{
	Intern	someRandomIntern;
	AForm	*form[4] = {someRandomIntern.makeForm("Invalid request Form", "Bender"), someRandomIntern.makeForm("Robotomy Request Form", "Bender"), someRandomIntern.makeForm("Shrubbery Creation Form", "Bender"), someRandomIntern.makeForm("Presidential Pardon Form", "Bender")};
	try
	{
		Bureaucrat strongB = Bureaucrat("Bob", 5);
		Bureaucrat weakB = Bureaucrat("Sam", 150);
		for (int i = 0; i < 4; i++)
		{
			std::cout << std::endl << std::string(21, '*') << "Test #" << i << std::string(21, '*') << std::endl;
			if (form[i])
			{
				std::cout << *form[i] << std::endl;
				strongB.signForm(*form[i]);
				std::cout << "🚩 Result for Bob: " << std::endl;
				strongB.executeForm(*form[i]);
				std::cout << "🚩 Result for Sam: " << std::endl;
				weakB.executeForm(*form[i]);
				delete form[i];
			}
			else
				std::cout << "Form not found" << std::endl;
			
		}
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
		for (int i = 0; i < 4; i++)
			delete form[i];
	}
}