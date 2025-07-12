#include "Form.hpp"
#include <iostream>

Form::Form()
	: _name("NONAME"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw GradeTooLowException();
	}
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

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too HIGH, Can't be below 1\n";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too LOW, Can't be above 150\n";
}

const char* Form::FormNotSignedException::what() const throw() {
	return "Form is not signed\n";
}

const std::string& Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& Form) {
	os << "Form Details:\n"
		<< "Name: " << Form.getName() << "\n"
		<< "Sign Grade: " << Form.getSignGrade() << "\n"
		<< "Execution Grade: " << Form.getExecGrade() << "\n"
		<< "Is Signed: " << (Form.getIsSigned() ? "Yes" : "No") << "\n";
	return os;
}

void Form::beSigned(const Bureaucrat &bur){
	if (this->_signGrade < bur.getGrade())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

void Form::execute(Bureaucrat const & executor) const{
	if (!this->_isSigned)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->beExecuted();
}