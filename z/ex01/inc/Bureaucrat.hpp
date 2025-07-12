#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int target);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string getName();
		int getGrade();
		void increment();
		void decrement();
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};
		void signForm(Form form);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream &o, Bureaucrat bur);

#endif