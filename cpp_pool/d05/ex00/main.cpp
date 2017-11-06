
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

int main()
{
	try
	{
		Bureaucrat b1("B1", 4);
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.decremGrade();
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << b1.getName() << std::endl;
	}

	try
	{
		Bureaucrat b2("B2", 0);
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << b2.getName() << std::endl;
	}

	try
	{
		Bureaucrat b3("B3", 149);
		std::cout << b3;
		b3.incremGrade();
		std::cout << b3;
		b3.incremGrade();
		std::cout << b3;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << b3.getName() << std::endl;
	}

	return (0);
}