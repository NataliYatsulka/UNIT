
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class Form;
class Bureaucrat;
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();
	void						execute(Bureaucrat const &executor) const;
	
protected:
private:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm		&operator=(PresidentialPardonForm const &rhs);
};

#endif