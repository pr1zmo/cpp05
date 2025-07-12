#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("NONAME") , _grade(1) {
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

int Bureaucrat::getGrade(){
	return this->_grade;
}

std::string Bureaucrat::getName(){
	return this->_name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name) {
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade too high, can't be higher than 150\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low, can't be lower than 1\n";
}

void Bureaucrat::increment(){
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::decrement(){
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream &o, Bureaucrat bur){
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return o;
}

void Bureaucrat::signForm(Form form){
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because the lowest grade to sign is " << form.getSignGrade() << "." << std::endl;
	}
}