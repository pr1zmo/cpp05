#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: Form("presidential pardon form", SIGN_GRADE, EXEC_GRADE) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("roboto form", SIGN_GRADE, EXEC_GRADE), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: Form("presidential pardon form", SIGN_GRADE, EXEC_GRADE), _target(other._target) {
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
		this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (Form::FormNotSignedException());
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}