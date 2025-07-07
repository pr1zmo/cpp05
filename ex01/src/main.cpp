#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 1);
		std::cout << b1 << std::endl;
		b1.increment();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;
		b2.decrement();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Charlie", 151);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Dave", 0);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f1("FormA", 1, 1);
		std::cout << f1 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f2("FormB", 151, 10);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f3("FormC", 10, 0);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat john("John", 50);
	Form fSign("FormSign", 75, 75);
	Form fFail("FormFail", 25, 25);

	std::cout << fSign << std::endl;
	john.signForm(fSign);
	std::cout << fSign << std::endl;

	std::cout << fFail << std::endl;
	john.signForm(fFail);
	std::cout << fFail << std::endl;

	john.signForm(fSign);

	return 0;
}
