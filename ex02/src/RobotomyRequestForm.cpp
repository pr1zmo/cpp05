#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
	: Form("roboto form", SIGN_GRADE, EXEC_GRADE) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("roboto form", SIGN_GRADE, EXEC_GRADE), _target(target){

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form("roboto form", SIGN_GRADE, EXEC_GRADE), _target(other._target) {
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

int randomAction() {
	std::cout << "* Drilling noises *\n";
	std::srand(std::time(0));
	return (std::rand() % 2);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (Form::FormNotSignedException());
	if (randomAction())
		std::cout << this->_target << " has been robotomized.\n";
	else
		std::cout << "Failed Robotomization for " << this->_target << ".\n";
}