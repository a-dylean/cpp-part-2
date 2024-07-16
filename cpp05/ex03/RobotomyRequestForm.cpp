#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> // for rand() and srand()
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm ("Robotomy Request Form", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm():
	AForm ("Robotomy Request Form", 72, 45, "undefined") {
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) {
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	RobotomyRequestForm::executeBehaviour() const {
	std::cout << "* DRILLING NOISES *" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number
    int randomNumber = std::rand();

    // 50% success rate
    if (randomNumber % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy on " << this->getTarget() << " failed." << std::endl;
    }
}