#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

// sign 145, exec 137;
#include "AForm.hpp"
#include <iostream>

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		static int const _reqSign = 145;
		static int const _reqExec = 137;
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};

#endif