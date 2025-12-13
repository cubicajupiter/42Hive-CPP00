#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact {
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_nbr;
		std::string darkest_secret;
};

class PhoneBook {
		Contact contacts[8];
		bool is_on;
		std::string input;
		void add (void);
		void search (void);
		void exit (void);
	public:
		void interface (void);
};

#endif
