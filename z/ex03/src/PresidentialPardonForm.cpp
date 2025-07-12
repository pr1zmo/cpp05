#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardon", 25, 5), _target("NONAME") {
	std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardon", 25, 5), _target(target){
	std::cout << "PresidentialPardonForm: Parameter constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm("PresidentialPardon", 25, 5), _target(other._target) {
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm: Copy assignment operator called\n";
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
