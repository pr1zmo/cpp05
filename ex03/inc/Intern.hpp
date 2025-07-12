#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Intern {
	public:
		Intern();
		~Intern();

		class FormDoesNotExistException : public std::exception{
			public:
				const char* what() const throw();
		};
		Form* makeForm(std::string formName, std::string target);
};

#endif