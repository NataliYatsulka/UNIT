
#include "Bureaucrat.hpp"

const int Bureaucrat::minGrade = 1;
const int Bureaucrat::maxGrade = 150;

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < minGrade)
		throw (GradeTooHighException());
	if (grade > maxGrade)
		throw (GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat]() DEST called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_name = rhs._name;
	this->_grade = rhs._grade;
	return (*this);
}

void	Bureaucrat::incremGrade()
{
	if (this->_grade - 1 < minGrade)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decremGrade()
{
	if (this->_grade + 1 > maxGrade)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " cannot sign " << f.getName() << " because " <<e.what() << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm(Form const &f)
{
	try
	{
		std::cout << this->_name << " executes " << f.getName() << " on " <<
			f.getTarget() << std::endl;
		f.tryExecute(*this);		
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " cannot execute " << f.getName() <<
			" because " << e.what() << std::endl;
	}
	catch (Form::FormNotSignedException &e)
	{
		std::cout << this->_name << " cannot execute " << f.getName() <<
			" because " << e.what() << std::endl;
	}
	return ;
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
	*this = src;
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator
	=(Bureaucrat::GradeTooHighException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (" Grade Too High");
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
	*this = src;
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator
	=(Bureaucrat::GradeTooLowException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (" Grade Too Low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << "<" << bureaucrat.getName() << ">, bureaucrat grade <" << bureaucrat.getGrade() << ">." << std::endl;
	return (o); 
}
