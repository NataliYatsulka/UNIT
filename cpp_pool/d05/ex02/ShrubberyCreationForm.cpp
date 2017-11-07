
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	Form("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "[ShrubberyCreationForm](std::string const&)"
		" Ctor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm]() Dtor called" << std::endl;
	return ;
}

void						ShrubberyCreationForm::execute(
	Bureaucrat const &executor) const
{
	std::string		filename("./");
	std::ofstream	ofs;

	filename += this->getTarget();
	filename += "_shrubbery";
	ofs.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail())
	{
		std::cout << "Error openning " << filename << std::endl;
		return ;
	}
	if (ofs.fail())
	{
		std::cout << "Error writting in  " << filename << std::endl;
		return ;
	}
	(void)executor;
	return ;
}
