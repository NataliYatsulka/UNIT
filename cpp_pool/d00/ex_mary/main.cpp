
#include <iostream>
#include <string>
#include "Phone_book.class.hpp"



int				main(void)
{
	Phone_book		phone[8];
	int			i = 0;
	int			j = 0;
	std::string	line;

	std::cout << "Enter some of this operation: ADD, SEARCH or EXIT:" << std::endl;
	while (std::getline(std::cin, line, '\n'))
	{		
		if (line == "ADD")
		{
			if (i < 8)
				phone[i].add_contact();
			else
				std::cout << "Sorry, but too many contacts to add!" << std::endl;
			i++;
		}
		else if (line == "SEARCH")
		{
			j = -1;
			std::cout << "SEARCH" << std::endl;
			while (++j < 8)
			{
				std::cout << "  j  |   first_name   |   last_name  |   nickname"<< std::endl;
				std::cout << phone[j].first_name << std::endl;
				std::cout << phone[j].last_name << std::endl;
				std::cout << phone[j].nickname << std::endl;
				std::cout << phone[j].login << std::endl;
				std::cout << phone[j].postal_address << std::endl;
				std::cout << phone[j].email_address << std::endl;
				std::cout << phone[j].phone_number << std::endl;
				std::cout << phone[j].birthday_date << std::endl;
				std::cout << phone[j].favorite_meal << std::endl;
				std::cout << phone[j].underwear_color << std::endl;
				std::cout << phone[j].darkest_secret << std::endl;
			}
		}
		else if (line == "EXIT")
		{
			std::cout << "The program quit and the contacts are lost forever!" << std::endl;
			break ;
		}
		if (i >= 8)
			std::cout << "Now you can enter only SEARCH or Exit" << std::endl;
		else
			std::cout << "Enter some of this operation: ADD, SEARCH or EXIT:" << std::endl;

	}


	i = -1;
	while (++i && i < 8)
	{
		std::cout << phone[i].first_name << std::endl;
		std::cout << phone[i].last_name << std::endl;
		std::cout << phone[i].nickname << std::endl;
		std::cout << phone[i].login << std::endl;
		std::cout << phone[i].postal_address << std::endl;
		std::cout << phone[i].email_address << std::endl;
		std::cout << phone[i].phone_number << std::endl;
		std::cout << phone[i].birthday_date << std::endl;
		std::cout << phone[i].favorite_meal << std::endl;
		std::cout << phone[i].underwear_color << std::endl;
		std::cout << phone[i].darkest_secret << std::endl;
	}


	return 0;
}
