
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class Form;
class Bureaucrat;

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm();
	void						execute(Bureaucrat const &executor) const;
	
protected:
private:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm		&operator=(RobotomyRequestForm const &rhs);
};

#endif
