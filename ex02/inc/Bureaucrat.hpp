#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();

		void signForm(Form& form);

		void executeForm(Form const &form);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat &bur);

#endif