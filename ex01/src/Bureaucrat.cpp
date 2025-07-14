#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: _name("NONAME"), _grade(1) {
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high, cannot be less than 1\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low, cannot be more than 150\n";
}

void Bureaucrat::increment() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat &bur){
	o << bur.getName() << ", Bureaucrat grade: " << bur.getGrade();
	return o;
}

void Bureaucrat::signForm(Form& form){
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " Signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}