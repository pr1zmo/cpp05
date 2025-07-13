#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

# undef  SIGN_GRADE
# define SIGN_GRADE 145
# undef  EXEC_GRADE
# define EXEC_GRADE 137

// sign 145, exec 137;
#include "Form.hpp"
#include <iostream>
#include <fstream>

class Form;

class ShrubberyCreationForm : public Form {
	private:
		std::string _target;
		void beExecuted(void) const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};

#endif