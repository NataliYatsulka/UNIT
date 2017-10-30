
#ifndef PHONE_BOOK_CLASS_H
#define PHONE_BOOK_CLASS_H

#include <iostream>
#include <string>

class Phone_book
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string login;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string birthday_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;
		Phone_book(void);
		~Phone_book(void);

		int		add_contact_to_list(void);
};

#endif
