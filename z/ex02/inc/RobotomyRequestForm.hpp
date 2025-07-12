#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

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
		virtual ~RobotomyRequestForm();
};

#endif