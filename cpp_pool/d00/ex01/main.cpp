
#include <iostream>
#include <string>
#include "Phone_book.class.hpp"


static void	add_to_list(Phone_book *phone, int i, std::string s)
{
	std::string line;
	std::cout << s << std::endl;
	if (std::cin.eof())
		exit(1);
	std::getline(std::cin, line, '\n');
	// std::cout << std::endl;
	while (line.empty())
	{
		std::cout << "Enter " << s << " about new contact:" << std::endl;
		if (std::cin.eof())
			exit(1);
		std::getline(std::cin, line, '\n');
	}
	switch (i)
	{
		case 0: phone->first_name = line;
		case 1: phone->last_name = line;
		case 2: phone->nickname = line;
		case 3: phone->login = line;
		case 4: phone->postal_address = line;
		case 5: phone->email_address = line;
		case 6: phone->phone_number = line;
		case 7: phone->birthday_date = line;
		case 8: phone->favorite_meal = line;
		case 9: phone->underwear_color = line;
		case 10: phone->darkest_secret = line;
	}
}

static void	add_contact(Phone_book *phone)
{
	add_to_list(phone, 0, "first_name");
	add_to_list(phone, 1, "last_name");
	add_to_list(phone, 2, "nickname");
	add_to_list(phone, 3, "login");
	add_to_list(phone, 4, "postal_address");
	add_to_list(phone, 5, "email_address");
	add_to_list(phone, 6, "phone_number");
	add_to_list(phone, 7, "birthday_date");
	add_to_list(phone, 8, "favorite_meal");
	add_to_list(phone, 9, "underwear_color");
	add_to_list(phone, 10, "darkest_secret");
}

int				main(void)
{
	Phone_book		phone[8];
	int			i = 0;
	int			j = 0;
	std::string	line;

	std::cout << "Enter some of this operation: ADD, SEARCH or EXIT:" << std::endl;
	if (std::cin.eof())
		exit(1);
	while (std::getline(std::cin, line, '\n'))
	{		
		if (line == "ADD")
		{
			if (i < 8)
				add_contact(&phone[i]);
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
