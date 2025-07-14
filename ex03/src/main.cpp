#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
	Bureaucrat highLevel("CEO", 1);
	Intern poorIntern;

	std::cout << "\n\033[1;36m==== TEST 1: Valid Forms - RobotomyRequest ====\033[0m\n";
	try {
		// Should successfully create form
		AForm* robotomy = poorIntern.makeForm("robotomy request", "Bender");
		
		// Test form functionality
		highLevel.signForm(*robotomy);
		highLevel.executeForm(*robotomy);
		
		delete robotomy;
	} catch (const std::exception& e) {
		std::cerr << "\033[31mUNEXPECTED ERROR: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 2: Valid Forms - PresidentialPardon ====\033[0m\n";
	try {
		AForm* pardon = poorIntern.makeForm("presidential pardon", "Zaphod");
		highLevel.signForm(*pardon);
		highLevel.executeForm(*pardon);
		delete pardon;
	} catch (const std::exception& e) {
		std::cerr << "\033[31mUNEXPECTED ERROR: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 3: Valid Forms - ShrubberyCreation ====\033[0m\n";
	try {
		AForm* shrub = poorIntern.makeForm("shrubbery creation", "Garden");
		highLevel.signForm(*shrub);
		highLevel.executeForm(*shrub);
		delete shrub;
	} catch (const std::exception& e) {
		std::cerr << "\033[31mUNEXPECTED ERROR: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 4: Invalid Form Name (Exact Match Required) ====\033[0m\n";
	try {
		// Should fail - extra space
		AForm* f1 = poorIntern.makeForm("robotomy request ", "Target");
		if (!f1) std::cout << "✓ Correctly returned NULL\n";
	} catch (const std::exception& e) {
		std::cerr << "\033[33m" << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 5: Case Sensitivity Test ====\033[0m\n";
	try {
		// Should fail - case sensitivity
		AForm* f2 = poorIntern.makeForm("Shrubbery Creation", "Target");
		if (!f2) std::cout << "✓ Correctly returned NULL\n";
	} catch (const std::exception& e) {
		std::cerr << "\033[33m" << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 6: Empty Form Name ====\033[0m\n";
	try {
		AForm* f3 = poorIntern.makeForm("", "Target");
		if (!f3) std::cout << "✓ Correctly returned NULL\n";
	} catch (const std::exception& e) {
		std::cerr << "\033[33m" << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 7: Unknown Form Type ====\033[0m\n";
	try {
		AForm* f4 = poorIntern.makeForm("tax form", "Target");
		if (!f4) std::cout << "✓ Correctly returned NULL\n";
	} catch (const std::exception& e) {
		std::cerr << "\033[33m" << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 8: Null Target ====\033[0m\n";
	try {
		// Should work - empty target is allowed
		AForm* f5 = poorIntern.makeForm("shrubbery creation", "");
		if (f5) {
			std::cout << "✓ Form created with empty target\n";
			std::cout << "Form name: " << f5->getName() << "\n";
			delete f5;
		}
	} catch (const std::exception& e) {
		std::cerr << "\033[31mUNEXPECTED ERROR: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 9: Multiple Forms ====\033[0m\n";
	try {
		AForm* forms[3];
		forms[0] = poorIntern.makeForm("robotomy request", "R2D2");
		forms[1] = poorIntern.makeForm("presidential pardon", "Marvin");
		forms[2] = poorIntern.makeForm("shrubbery creation", "Forest");

		for (int i = 0; i < 3; ++i) {
			if (forms[i]) {
					highLevel.signForm(*forms[i]);
					highLevel.executeForm(*forms[i]);
					delete forms[i];
			}
		}
	} catch (const std::exception& e) {
		std::cerr << "\033[31mUNEXPECTED ERROR: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[1;36m==== TEST 10: Memory Leak Check ====\033[0m\n";
	// Run with valgrind to verify no leaks
	AForm* temp = poorIntern.makeForm("presidential pardon", "Test");
	delete temp;  // Should clean up properly
	std::cout << "✓ Cleaned up single form successfully\n";

	return 0;
}