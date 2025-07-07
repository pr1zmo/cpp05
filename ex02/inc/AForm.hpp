#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

		public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		class GradeTooLowException : public std::exception {
			public:
			const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
			const char* what() const throw();
		};
		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bur);
		virtual void	beExecuted(void) const = 0;
};

std::ostream& operator<<(std::ostream& o, AForm const &AForm);

#endif