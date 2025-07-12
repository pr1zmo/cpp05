#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

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
		class GradeTooHighException : public std::exception{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char * what() const throw();
		};
		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(AForm &f);
		void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif