#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main()
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	ShrubberyCreationForm	f1 = ShrubberyCreationForm("zizi");
	RobotomyRequestForm		f2 = RobotomyRequestForm("a rat");
	PresidentialPardonForm	f3 = PresidentialPardonForm("Captain Sparrow");

	try{
		thiery.executeForm(f1);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try {
		sophie.signForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		thiery.signForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sophie.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		thiery.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		lou.signForm(f2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		lou.executeForm(f2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		lou.signForm(f3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		lou.executeForm(f3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		PresidentialPardonForm	f4 = f3;
		thiery.signForm(f4);
		thiery.executeForm(f4);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}