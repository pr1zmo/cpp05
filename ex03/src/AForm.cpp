#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("NONAME"), _signGrade(1), _execGrade(1), _isSigned(0) {
}

const char* AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high\n");
}

const char* AForm::FormNotSignedException::what(void) const throw() {
	return ("The form has not been signed.");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low\n");
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signGrade(sign_grade), _execGrade(exec_grade){
	if (this->_execGrade > 150 || this->_signGrade > 150)
		throw AForm::GradeTooLowException();
	if (this->_execGrade < 1 || this->_signGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned) {
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {
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

std::ostream &operator<<(std::ostream& o, const AForm &AForm){
	o << "AForm \"" << AForm.getName() << "\" [Sign grade: " << AForm.getSignGrade()
		<< ", Exec grade: " << AForm.getExecGrade()
		<< ", Signed: " << (AForm.getIsSigned() ? "yes" : "no") << "]";
	return o;
}

void AForm::beSigned(Bureaucrat bur){
	if (bur.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	else if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	else
		this->beExecuted();
}