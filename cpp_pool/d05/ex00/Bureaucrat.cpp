
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) 
{
	this->_name = name;
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &)
{
	return (*this);
}

void	Bureaucrat::incremGrade()
{
	this->_grade++;
}

void	Bureaucrat::decremGrade()
{
	this->_grade--;
}


std::string	const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}


Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{	
	*this->src;
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator
	=(Bureaucrat::GradeTooHighException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}


Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	return ;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this->src;
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator
	=(Bureaucrat::GradeTooLowException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (o); 
}
