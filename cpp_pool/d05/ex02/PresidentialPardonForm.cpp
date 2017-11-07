
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	Form("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "[PresidentialPardonForm](std::string const&)"
	" Ctor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm]() Dtor called" << std::endl;
	return ;
}

void						PresidentialPardonForm::execute(
	Bureaucrat const &executor) const
{
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox."
			  << std::endl;
	(void)executor;
	return ;
}
