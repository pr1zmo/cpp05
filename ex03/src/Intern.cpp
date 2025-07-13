#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern(){
}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
}

const char* Intern::FormDoesNotExistException::what() const throw(){
	return "The specified form does not exist\n";
}

static Form	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string formName, std::string target){
	Form *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"shrubbery creation", "presidential pardon", "Roboto request"};
	int i = 0;
	for (std::strinc s : forms){
		if (s.compare(formName)){
			std::cout << "Intern creates " << form_to_create << " now" << std::endl;
			return (allForms[i](target));
		}
		i++;
	}
	throw Intern::FormDoesNotExistException();
	return NULL;
}