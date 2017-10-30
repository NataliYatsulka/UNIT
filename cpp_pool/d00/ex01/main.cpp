
#include "Phone_book.class.hpp"

static void	add_contact_to_list(Phone_book *phone)
{
	std::cout << "Please, enter your first_name" << std::endl;
	std::getline(std::cin, phone->first_name);
	std::cout << "Please, enter your last_name" << std::endl;
	std::getline(std::cin, phone->last_name);
	std::cout << "Please, enter your nickname" << std::endl;
	std::getline(std::cin, phone->nickname);
	std::cout << "Please, enter your login" << std::endl;
	std::getline(std::cin, phone->login);
	std::cout << "Please, enter your postal_address" << std::endl;
	std::getline(std::cin, phone->postal_address);
	std::cout << "Please, enter your email_address" << std::endl;
	std::getline(std::cin, phone->email_address);
	std::cout << "Please, enter your phone_number" << std::endl;
	std::getline(std::cin, phone->phone_number);
	std::cout << "Please, enter your birthday_date" << std::endl;
	std::getline(std::cin, phone->birthday_date);
	std::cout << "Please, enter your favorite_meal" << std::endl;
	std::getline(std::cin, phone->favorite_meal);
	std::cout << "Please, enter your underwear_color" << std::endl;
	std::getline(std::cin, phone->underwear_color);
	std::cout << "Please, enter your darkest_secret" << std::endl;
	std::getline(std::cin, phone->darkest_secret);
}

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
				add_contact_to_list(&phone[i]);
			else
				std::cout << "Sorry, but too many contacts to add!" << std::endl;
			// std::cout << "OKKKKKK" << std::endl;
			// std::cout << phone[i].first_name << std::endl;
			// std::cout << phone[i].last_name << std::endl;
			// std::cout << phone[i].nickname << std::endl;
			// std::cout << phone[i].login << std::endl;
			// std::cout << phone[i].postal_address << std::endl;
			// std::cout << phone[i].email_address << std::endl;
			// std::cout << phone[i].phone_number << std::endl;
			// std::cout << phone[i].birthday_date << std::endl;
			// std::cout << phone[i].favorite_meal << std::endl;
			// std::cout << phone[i].underwear_color << std::endl;
			// std::cout << phone[i].darkest_secret << std::endl;
		}
		else if (line == "SEARCH")
		{
			j = -1;
			std::cout << "SEARCH" << std::endl;
			while (++j && j < 8)
			{
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
