
#include <iostream>
#include "Form.hpp"

const int	Form::minGrade = 1;
const int	Form::maxGrade = 150;

Form::Form(std::string const &name, int sGrade, int eGrade)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name),
	_sGrade(sGrade),
	_eGrade(eGrade),
	_isSigned(false)
{
	std::cout << "[Form](std::string const&,int,int) Ctor called" << std::endl;
	if (sGrade < Form::minGrade || eGrade < Form::minGrade)
		throw GradeTooHighException();
	if (sGrade > Form::maxGrade || eGrade > Form::maxGrade)
		throw GradeTooLowException();
	return ;
}

Form::GradeTooHighException::GradeTooHighException() :
	std::exception()
{
	std::cout << "[GradeTooHighException]() Ctor called" << std::endl;
	return ;
}

Form::GradeTooLowException::GradeTooLowException() :
	std::exception()
{
	std::cout << "[GradeTooLowException]() Ctor called" << std::endl;
	return ;
}
Form::GradeTooHighException::GradeTooHighException(
	GradeTooHighException const &rhs) : std::exception()
{
	std::cout << "[GradeTooHighException](cpy) Ctor called" << std::endl;
	(void)rhs;
	return ;
}

Form::GradeTooLowException::GradeTooLowException(
	GradeTooLowException const &rhs) : std::exception()
{
	std::cout << "[GradeTooLowException](cpy) Ctor called" << std::endl;
	(void)rhs;
	return ;
}

Form::~Form()
{
	std::cout << "[Form]() Dtor called" << std::endl;
	return ;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "[GradeTooHighException]() Dtor called" << std::endl;
	return ;
}
Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "[GradeTooLowException]() Dtor called" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form(" << rhs.getSGrade() << "," << rhs.getEGrade() <<
		"):"<< rhs.getName() << " signed:" << std::boolalpha <<
		rhs.getIsSigned();
	return (o);
}

std::string const &Form::getName(void) const{return this->_name;}
int		Form::getSGrade(void) const{return this->_sGrade;}
int		Form::getEGrade(void) const{return this->_eGrade;}
bool	Form::getIsSigned(void) const
{return this->_isSigned;}

void	Form::beSigned(Bureaucrat const &b)
	throw(GradeTooLowException)
{
	if (!this->_isSigned)
	{
		if (b.getGrade() > this->_sGrade)
			throw Form::GradeTooLowException();		
		this->_isSigned = true;
	}
	else
		std::cout << this->_name << " is already signed..." << std::endl;
		return ;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
