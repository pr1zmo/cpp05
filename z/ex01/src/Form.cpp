#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
	: _name("NONAME"), _signGrade(1), _execGrade(1), _isSigned(0) {
	std::cout << "Form: Default constructor called" << std::endl;
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high\n");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low\n");
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signGrade(sign_grade), _execGrade(exec_grade){
	if (this->_execGrade > 150 || this->_signGrade > 150)
		throw Form::GradeTooLowException();
	if (this->_execGrade < 1 || this->_signGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Construtor with parameters\n";
}

Form::Form(const Form& other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned) {
	std::cout << "Form: Copy constructor called" << std::endl;
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

std::ostream &operator<<(std::ostream& o, Form form){
	o << "Form \"" << form.getName() << "\" [Sign grade: " << form.getSignGrade()
		<< ", Exec grade: " << form.getExecGrade()
		<< ", Signed: " << (form.getIsSigned() ? "yes" : "no") << "]";
	return o;
}

void Form::beSigned(Bureaucrat bur){
	if (bur.getGrade() <= this->getSignGrade())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}