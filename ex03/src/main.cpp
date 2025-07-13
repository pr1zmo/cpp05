#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *a = new Bureaucrat();
	Intern *z = new Intern();
	Form *b = z->makeForm("SomeRandomForm", "Clown");
	b = z->makeForm("PresidentialPardonForm", "Clown");
	// Form *b = new PresidentialPardonForm("Clown");
	// Form *c = new RobotomyRequestForm("Bender");
	// Form *d = new ShrubberyCreationForm("Christmas");
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << a;
	std::cout << b;
	std::cout << std::endl;

	try
	{
		b->beSigned(*a);
		// b->execute(*a);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl;
	std::cout << b;
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete a;
	delete b;
	delete z;
	std::cout << std::endl;
}
