#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

# undef  SIGN_GRADE
# define SIGN_GRADE 25
# undef  EXEC_GRADE
# define EXEC_GRADE 5

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		void beExecuted(void);

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
};

#endif