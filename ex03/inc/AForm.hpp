#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		int const _signGrade;
		int const _execGrade;
		bool _isSigned;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual void beExecuted(void) const = 0;
		void execute(Bureaucrat const & executor) const;
		class FormNotSignedException: public std::exception {
		public:
			virtual const char* what(void) const throw();
		};
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
		virtual ~AForm();
};

std::ostream& operator<<(std::ostream &o, const AForm &form);

#endif