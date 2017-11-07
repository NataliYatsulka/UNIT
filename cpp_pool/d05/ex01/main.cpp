
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test1(Bureaucrat &b, Form &f)
{
	std::cout << "\033[35mtest1: \033[0m" << std::endl;
	
	std::cout << b.getName() << "(" << b.getGrade() <<
		") trying to sign " << f.getName() << "(" << f.getSGrade() <<
		")" << std::endl;
	b.signForm(f);
	std::cout << std::endl;
	return ;
}

void	test2()
{
	try
	{
		std::cout << "Creating Form @ grade 0, 10" << std::endl;
		Form b("Test", 0, 10);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Catched GradeTooLowException: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Creating Form @ grade 10, 151" << std::endl;
		Form b("Test", 10, 151);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Catched GradeTooLowException: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	
	return ;
}

int		main(void)
{
	Bureaucrat		b1("A", Bureaucrat::minGrade);
	Bureaucrat		b2("B", Bureaucrat::maxGrade);
	Form			f1("AAAA", 1, 150);
	Form			f2("BBBB", 150, 1);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << std::endl;

	test1(b1, f2);
	test1(b2, f2);
	test1(b1, f1);
	test1(b2, f2);
	test2();

	return (0);
}
