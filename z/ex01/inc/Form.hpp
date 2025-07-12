#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		int const _signGrade;
		int const _execGrade;
		bool _isSigned;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		class GradeTooLowException : public std::exception{
			public:
				const char* what(void) const throw();
		};
		class GradeTooHighException : public std::exception{
			public:
				const char* what(void) const throw();
		};
		const std::string& getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat bur);
		~Form();
};

std::ostream& operator<<(std::ostream &o, Form form);

#endif