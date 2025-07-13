#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

		public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
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
		void beSigned(const Bureaucrat &bur);
		virtual void	beExecuted(void) const = 0;
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& o, Form const &Form);

#endif