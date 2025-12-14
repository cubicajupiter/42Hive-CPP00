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
	std::cout << "Welcome to the PhoneBook!\nUsage:\n";
	while (is_on) {
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
	static unsigned int		i;
	Contact					con;

	std::cout << "Contact's first name: ";
	std::cin >> con.first_name;
	std::cout << "Contact's last name: ";
	std::cin >> con.last_name;
	std::cout << "Contact's nickname: ";
	std::cin >> con.nickname;
	std::cout << "Contact's phone number: ";
	std::cin >> con.phone_nbr;
	std::cout << "Contact's darkest secret: ";
	std::cin >> con.darkest_secret;
	con.index = i % 8;
	contacts[con.index] = con;
	if (i < 8)
		len++;
	std::cout << "Contact added!" << std::endl;
	i++;
}

void	PhoneBook::search(void) {
	std::cout << '\n';
	for (const Contact &con : contacts) {
		if (con.is_filled())
			std::cout << std::right << std::setw(10) << con.index << '|'\
				<< std::right << std::setw(10) << con.truncate(con.first_name) << '|'\
				<< std::right << std::setw(10) << con.truncate(con.last_name) << '|'\
				<< std::right << std::setw(10) << con.truncate(con.nickname) << std::endl;
	}
	display_choice();
}

void	PhoneBook::display_choice(void) {
	std::stringstream	ss;
	int					index;

	while (1) {
		std::cout << "Please enter the index of the contact to display: ";
		std::cin >> input;
		ss.str("");
		ss.clear();
		ss << input;
		ss >> index;
		if (is_inrange(index)) {
			std::cout << "\nDISPLAYING CONTACT INFORMATION"  << std::endl;
			std::cout << "\tFirst Name: " << contacts[index].first_name << '\n'
			<< "\tLast Name: " << contacts[index].last_name << '\n'
			<< "\tNickname: " << contacts[index].nickname << '\n'
			<< "\tPhone Number: " << contacts[index].phone_nbr << '\n'
			<< "\tDarkest Secret: " << contacts[index].darkest_secret << '\n' << std::endl;
			break ;
		}
	}
}

bool	PhoneBook::is_inrange(int index) {
	if (index > 7 || index < 0 || index >= len) {
		std::cout << "Index out of range. Please enter a valid existing index (0-7)." << std::endl;
		return false;
	}
	return true;
}

void	PhoneBook::exit(void) {
	is_on = false;
}