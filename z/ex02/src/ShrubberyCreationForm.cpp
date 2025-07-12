#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreation", 145, 137), _target("NONAME") {
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreation", 145, 137), _target(target){
	std::cout << "ShurbberyCreationForm: parameter constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm("ShrubberyCreation", 145, 137), _target(other._target) {
	std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm: Copy assignment operator called\n";
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

void ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";

	file.open(filename.c_str());

	file << "        ccee88oo" << std::endl;
	file << "      C8O8O8Q8PoOb o8oo" << std::endl;
	file << "    dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "   CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "       6OuU  /p u gcoUodpP" << std::endl;
	file << "          \\\\//  /douUP" << std::endl;
	file << "            \\\\////" << std::endl;
	file << "             |||/\\" << std::endl;
	file << "             |||\\/" << std::endl;
	file << "             |||||" << std::endl;
	file << "       .....//||||\\...." << std::endl;

	file.close();
}
