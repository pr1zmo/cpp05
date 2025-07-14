#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("shrubbery form", SIGN_GRADE, EXEC_GRADE), _target("NONAME") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("shrubbery form", SIGN_GRADE, EXEC_GRADE), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other), _target(other._target) {
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void asciiTree(std::string target) {
	std::ofstream outfile((target + "_shrubbery").c_str());

	if (!outfile.is_open()) {
		std::cerr << "Error: Could not open file " << target + "_shrubbery" << std::endl;
		return;
	}

	outfile << "        ccee88oo" << std::endl;
	outfile << "      C8O8O8Q8PoOb o8oo" << std::endl;
	outfile << "    dOB69QO8PdUOpugoO9bD" << std::endl;
	outfile << "   CgggbU8OU qOp qOdoUOdcb" << std::endl;
	outfile << "       6OuU  /p u gcoUodpP" << std::endl;
	outfile << "          \\\\//  /douUP" << std::endl;
	outfile << "            \\\\////" << std::endl;
	outfile << "             |||/\\" << std::endl;
	outfile << "             |||\\/" << std::endl;
	outfile << "             |||||" << std::endl;
	outfile << "       .....//||||\\...." << std::endl;

	outfile.close();
}
 
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (Form::FormNotSignedException());
	asciiTree(this->_target);
}