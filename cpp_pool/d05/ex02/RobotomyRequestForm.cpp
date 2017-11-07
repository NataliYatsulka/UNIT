
#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	Form("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "[RobotomyRequestForm](std::string const&)"
		" Ctor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm]() Dtor called" << std::endl;
	return ;
}

void						RobotomyRequestForm::execute(
	Bureaucrat const &executor) const
{
	std::cout << "Makes some drilling noises. ";
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << "Robotomization failed on " << this->getTarget() <<
			std::endl;
	(void)executor;
	return ;
}
