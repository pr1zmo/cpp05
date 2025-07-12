#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("NONAME", SIGN_GRADE, EXEC_GRADE) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, SIGN_GRADE, EXEC_GRADE) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other._target, SIGN_GRADE, EXEC_GRADE) {
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::beExecuted(void) const {
	std::ofstream file;
	std::cout << "WWWWWWWWWWWWWWWWWWWWWWHAT??? \"" << this->_target << "\""<< std::endl;
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