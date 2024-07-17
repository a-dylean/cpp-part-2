#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &obj);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
	void executeBehaviour() const;
};

#endif