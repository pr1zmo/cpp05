#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("NONAME", SIGN_GRADE, EXEC_GRADE) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(target, SIGN_GRADE, EXEC_GRADE) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other._target, SIGN_GRADE, EXEC_GRADE) {
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

void RobotomyRequestForm::beExecuted(void){
	std::cout << "* Drilling noises *\n";
	std::srand(std::time(0));
	int rand = std::rand() % 2;
	if (rand)
		std::cout << this->_target << " has been robotomized.\n";
	else
		std::cout << "Failed Robotomization for " << this->_target << ".\n";
}