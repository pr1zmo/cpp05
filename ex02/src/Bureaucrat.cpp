#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: _name("Default Bureaucrat"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too HIGH, Can't be below 1\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too LOW, Can't be above 150\n";
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::increment(){
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << "Bureaucrat: Incremented grade to " << this->_grade << std::endl;
}

void Bureaucrat::decrement(){
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << "Bureaucrat: Decremented grade to " << this->_grade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm &f){
	try{
		f.beSigned(*this);
		std::cout << this->getName() << " Signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Could not execute form " << form.getName() << " Because "
		<< e.what() << std::endl;
	}
}