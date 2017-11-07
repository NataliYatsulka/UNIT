
#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <ctime>

int							main(void)
{
	Bureaucrat		b("PPPPP", Bureaucrat::maxGrade);
	Bureaucrat		bo("LALALA", Bureaucrat::minGrade);
	Form			*form1 = new PresidentialPardonForm("AAA");
	Form			*form2 = new RobotomyRequestForm("SSS");
	Form			*form3 = new ShrubberyCreationForm("VVV");

	std::cout << std::endl;	
	bo.executeForm(*form1);
	std::cout << std::endl;
	bo.signForm(*form1);
	std::cout << std::endl;
	b.executeForm(*form1);
	std::cout << std::endl;
	bo.executeForm(*form1);
	std::cout << std::endl;
	std::cout << std::endl;	
	std::cout << std::endl;	
	
	srand(time(NULL));
	bo.executeForm(*form2);
	std::cout << std::endl;
	bo.signForm(*form2);
	std::cout << std::endl;
	b.executeForm(*form2);
	std::cout << std::endl;
	bo.executeForm(*form2);
	bo.executeForm(*form2);
	bo.executeForm(*form2);
	std::cout << std::endl;
	std::cout << std::endl;	
	std::cout << std::endl;
	
	bo.executeForm(*form3);
	std::cout << std::endl;
	bo.signForm(*form3);
	std::cout << std::endl;
	b.executeForm(*form3);
	std::cout << std::endl;
	bo.executeForm(*form3);
	std::cout << std::endl;	
	delete form1;
	delete form2;
	delete form3;
	return (0);
}
