#include "Form.hpp"
#include <iostream>

Form::Form()
	: _name("NONAME"), _isSigned(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw GradeTooLowException();
	}
	std::cout << "Form: Parameterized constructor called" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "Form: Copy constructor called" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form: Destructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too HIGH, Can't be below 1\n";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too LOW, Can't be above 150\n";
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

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form Details:\n"
		<< "Name: " << form.getName() << "\n"
		<< "Sign Grade: " << form.getSignGrade() << "\n"
		<< "Execution Grade: " << form.getExecGrade() << "\n"
		<< "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n";
	return os;
}

void Form::beSigned(const Bureaucrat &bur){
	if (this->_signGrade < bur.getGrade())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}