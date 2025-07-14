#include "Form.hpp"
#include <iostream>

Form::Form()
	: _name("NONAME"), _isSigned(false), _signGrade(1), _execGrade(1) {
}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name) , _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	*this = other;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form Details:" << std::endl;
	os << "Name: " << form.getName() << std::endl;
	os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	os << "Sign Grade: " << form.getSignGrade() << std::endl;
	os << "Execution Grade: " << form.getExecGrade() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form's Grade is too high\n";
}

const char* Form:: GradeTooLowException::what() const throw() {
	return "Form's Grade is too low\n";
}

const char* Form::FormNotSignedException::what() const throw() {
	return "Form is not signed\n";
}

void Form::beSigned(Bureaucrat &bur){
	if (bur.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// void Form::execute(Bureaucrat const &executor) const {
// 	(void)executor;
// }