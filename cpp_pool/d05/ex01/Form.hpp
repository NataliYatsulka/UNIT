
#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class Form
{
public:
	static const int	minGrade;
	static const int	maxGrade;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &src);
		virtual ~GradeTooHighException() throw();

		virtual const char *what() const throw();
	private:
		GradeTooHighException& operator=(GradeTooHighException const &rhs);
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &src);
		virtual ~GradeTooLowException() throw();

		virtual const char *what() const throw();
	private:
		GradeTooLowException& operator=(GradeTooLowException const &rhs);
	};

	virtual ~Form();
	Form(std::string const &name, int sGrade, int eGrade)
		throw(GradeTooHighException, GradeTooLowException);

	std::string const			&getName(void) const;
	int							getSGrade(void) const;
	int							getEGrade(void) const;
	bool						getIsSigned(void) const;

	void						beSigned(Bureaucrat const &b)
		throw(GradeTooLowException);

	Form();
	Form(Form const &src);
	Form	&operator=(Form const &rhs);
	
private:
	std::string const			_name;
	int const					_sGrade;
	int const					_eGrade;
	bool						_isSigned;
};

std::ostream					&operator<<(std::ostream &o, Form const &rhs);

#endif
