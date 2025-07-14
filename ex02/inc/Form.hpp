#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _isSigned;
		int const _signGrade;
		int const _execGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &bur);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& o, Form &form);

#endif