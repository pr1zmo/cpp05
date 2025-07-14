#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

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

static AForm	*createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm *createdForm = NULL;
	const std::string	formsNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(*formsFun[])(std::string target) = {&createShrubbery, &createRobotomy, &createPresident};

	for (size_t i = 0; i < name.size(); i++) {
		if (name[i] >= 'A' && name[i] <= 'Z') {
			name[i] = name[i] + ('a' - 'A');
		}
	}
	for (size_t cur = 0; cur < (sizeof(formsNames) / sizeof(formsNames[0])); cur++)
	{
		if (name == formsNames[cur])
		{
			createdForm = formsFun[cur](target);
			break;
		}
	}
	if (!createdForm)
		std::cout << "There is no form with the name \"" << name << "\", but I can do the following forms : \"shrubbery creation\", \"robotomy creation\", \"presidential pardon\"." << std::endl; 
	return createdForm;
}