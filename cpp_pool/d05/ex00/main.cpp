
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

int main()
{
	try
	{
		Bureaucrat b1("B1", 4);
		std::cout << b1.getName() << ": "<< std::endl;
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.decremGrade();
		std::cout << b1;
		b1.decremGrade();
		std::cout << b1;
		b1.decremGrade();
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
		b1.incremGrade();
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("B2", -1);
		std::cout << b2.getName() << ": "<< std::endl;
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("B3", 149);
		std::cout << b3.getName() << ": "<< std::endl;
		std::cout << b3;
		b3.incremGrade();
		std::cout << b3;
		b3.incremGrade();
		std::cout << b3;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << e.what() << std::endl;
	}

	return (0);
}