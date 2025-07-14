#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotoRequest", 72, 45), _target("NONAME") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotoRequest", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm("RobotoRequest", 72, 45), _target(other._target) {
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::srand(std::time(0));
	int rand = std::rand() % 2;
	if (rand)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "Failed: " << this->_target << "." << std::endl;
}