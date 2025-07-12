#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("John Doe", 50);
		std::cout << bureaucrat << std::endl;

		bureaucrat.increment();
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrement();
		std::cout << bureaucrat << std::endl;

		// Uncommenting the following line will throw an exception
		// Bureaucrat invalidBureaucrat("Invalid", 200);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat invalidBureaucrat("Invalid", 0); // This will throw an exception
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat invalidBureaucrat("Invalid", 151); // This will throw an exception
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}