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

void ShrubberyCreationForm::beExecuted(void){
	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs) {
		std::cerr << "Error: Could not create file " << this->_target + "_shrubbery" << std::endl;
		return;
	}

	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\\\ //  ~" << std::endl;
	ofs << "_- -   | | _- _" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "       // \\\\" << std::endl;

	ofs.close();
}