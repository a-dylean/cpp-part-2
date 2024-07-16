#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		void	executeBehaviour() const;
};

#endif
