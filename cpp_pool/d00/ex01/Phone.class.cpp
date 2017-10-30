
#include "Phone_book.class.hpp"



Phone_book::Phone_book(void){
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

int		Phone_book::_nbContacts = 0;
