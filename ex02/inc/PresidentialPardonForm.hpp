#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

# undef  SIGN_GRADE
# define SIGN_GRADE 72
# undef  EXEC_GRADE
# define EXEC_GRADE 45

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor)const;
};

#endif