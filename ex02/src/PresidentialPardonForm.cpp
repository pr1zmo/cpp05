#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("NONAME", SIGN_GRADE, EXEC_GRADE) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target, SIGN_GRADE, EXEC_GRADE) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other._target, SIGN_GRADE, EXEC_GRADE) {
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::beExecuted(void){
	std::cout << this->_target << " Has been pardoned by Zaphod Beeblebrox.\n";
}