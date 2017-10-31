
#include "Phone_book.class.hpp"



Phone_book::Phone_book(void){
	this->Phone_book::_nbContacts = 8;
	// Phone_book::_nbContacts++;
	// if (Phone_book::_nbContacts == 8)
	// 	std::cout << "Phone_book is full" << std::endl;
	return ;
}

Phone_book::~Phone_book(void){
	// if (Phone_book::_nbContacts == 8)
	// 	std::cout << "Phone_book is destroyed" << std::endl;
	// Phone_book::_nbContacts++;
	return ;
}

void		Phone_book::add_to_list(int i, std::string s)
{
	std::string line;
	std::cout << s << std::endl;
	std::getline(std::cin, line, '\n');
	// std::cout << std::endl;
	while (line.empty())
	{
		std::cout << "Enter " << s << " about new contact:" << std::endl;
		std::getline(std::cin, line, '\n');
	}
	switch (i)
	{
		case 0: this->first_name = line;
		case 1: this->last_name = line;
		case 2: this->nickname = line;
		case 3: this->login = line;
		case 4: this->postal_address = line;
		case 5: this->email_address = line;
		case 6: this->phone_number = line;
		case 7: this->birthday_date = line;
		case 8: this->favorite_meal = line;
		case 9: this->underwear_color = line;
		case 10: this->darkest_secret = line;
	}
}

void	Phone_book::add_contact()
{
	add_to_list(0, "first_name");
	add_to_list(1, "last_name");
	add_to_list(2, "nickname");
	add_to_list(3, "login");
	add_to_list(4, "postal_address");
	add_to_list(5, "email_address");
	add_to_list(6, "phone_number");
	add_to_list(7, "birthday_date");
	add_to_list(8, "favorite_meal");
	add_to_list(9, "underwear_color");
	add_to_list(10, "darkest_secret");
}


// int		Phone_book::_nbContacts = 8;
