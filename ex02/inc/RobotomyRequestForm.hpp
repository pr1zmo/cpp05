#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

# undef  SIGN_GRADE
# define SIGN_GRADE 72
# undef  EXEC_GRADE
# define EXEC_GRADE 45

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		void beExecuted(void) const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
};

#endif