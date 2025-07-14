#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

# undef  SIGN_GRADE
# define SIGN_GRADE 25
# undef  EXEC_GRADE
# define EXEC_GRADE 5

#include <iostream>
#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public Form {
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor)const;
};

#endif