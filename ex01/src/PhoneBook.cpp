//prompt user input
//only one of three commands - else usage instructions
//No empty fields
//ADD: propt info input one field at a time.
//SEARCH: for index choice, display right-aligned 4 colums 10 chars wide with | delimiter btwn columsn. if longer than 10, truncate end with '.'
//			-> prompt user again for index
//			-> after index choice, then display contact information one field per line.
//EXIT: quit program and lose all contacts.

#include "PhoneBook.hpp"

void	PhoneBook::interface(void) {
	is_on = true;
	while (is_on) {
		std::cout << "Welcome to the PhoneBook!\nUsage:\n";
		std::cout << "Input <ADD> to add a contact\n";
		std::cout << "Input <SEARCH> to search for a contact\n";
		std::cout << "Input <EXIT> to exit the app." << std::endl;
		std::cout << "Please enter your input: ";
		std::cin >> input; //use stringstreams for better control over input. permit only strings.
		if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
		else if (input == "EXIT")
			exit();
	}
}

void	PhoneBook::add(void) {
	Contact					con;
	static unsigned int		i;

	std::cout << "Please enter contact's first name: ";
	std::cin >> con.first_name;
	std::cout << "Please enter contact's last name: ";
	std::cin >> con.last_name;
	std::cout << "Please enter contact's nickname: ";
	std::cin >> con.nickname;
	std::cout << "Please enter contact's phone number: ";
	std::cin >> con.phone_nbr;
	std::cout << "Please enter contact's darkest secret: ";
	std::cin >> con.darkest_secret;
	contacts[i % 8] = con;
	i++;
}

void	PhoneBook::search(void) {
	;
}

void	PhoneBook::exit(void) {
	is_on = false;
}
