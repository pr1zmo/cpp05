#include "AForm.hpp"
#include <iostream>

AForm::AForm()
	: _name("NONAME"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	*this = other;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too HIGH, Can't be below 1\n";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too LOW, Can't be above 150\n";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed\n";
}

const std::string& AForm::getName() const {
	return _name;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << "AForm Details:\n"
		<< "Name: " << AForm.getName() << "\n"
		<< "Sign Grade: " << AForm.getSignGrade() << "\n"
		<< "Execution Grade: " << AForm.getExecGrade() << "\n"
		<< "Is Signed: " << (AForm.getIsSigned() ? "Yes" : "No") << "\n";
	return os;
}

void AForm::beSigned(const Bureaucrat &bur){
	if (this->_signGrade < bur.getGrade())
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->beExecuted();
}