#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &obj) {
	if (this != &obj)
		*this = obj;
}

Intern	&Intern::operator=(const Intern &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string formName[] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	int index = -1;
	AForm *form = NULL;
	for (int i = 0; i < 3; i++){
		if (name == formName[i])
		{
			index = i;
			std::cout << "Intern creates " << formName[index] << std::endl;
			break;	
		}
	}
	switch (index)
	{
	case 0 :
		form = new ShrubberyCreationForm(target);
		return (form);
	case 1 :
		form = new RobotomyRequestForm(target);
		return (form);
	case 2 :
		form = new PresidentialPardonForm(target);
		return (form);
	default:
		std::cout <<"Intern can't create a form, form's name is incorrect" << std::endl;
		break;
	}
	return (NULL);
}