
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
public:
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);

	void	incremGrade();
	void	decremGrade();

	std::string	const	&getName() const;
	int					getGrade() const;

	public:
		class	GradeTooHighException: public std::exception
		{
			public:
			GradeTooHighException();
			~GradeTooHighException() throw();
			GradeTooHighException(GradeTooHighException const &src);
			GradeTooHighException	&operator=(GradeTooHighException const &rhs);

			char const	*what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
			GradeTooLowException();
			~GradeTooLowException() throw();
			GradeTooLowException(GradeTooLowException const &src);
			GradeTooLowException	&operator=(GradeTooLowException const &rhs);

			char const	*what() const throw();
		};

	private:
		std::string	_name;
		int			_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif
