/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:42:02 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/22 15:58:12 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	clearScreen(void);

std::string	readInput(std::istream& in) {
	std::string		input;

	while (std::getline(in, input)) {
		if (!input.empty())
			break;
	}
	return input;
}

void	PhoneBook::interface(void) {
	this->_is_on = true;
	while (this->_is_on) {
		clearScreen();
		std::cout << "Welcome to the PhoneBook!\nUsage:\n";
		std::cout << "Input <ADD> to add a contact\n";
		std::cout << "Input <SEARCH> to search for a contact\n";
		std::cout << "Input <EXIT> to exit the app." << std::endl;
		std::cout << "Please enter your input: ";
		std::cin >> this->_input;
		if (this->_input == "ADD")
			add();
		else if (this->_input == "SEARCH")
			search();
		else if (this->_input == "EXIT")
			exit();
	}
}

void	PhoneBook::add(void) {
	static unsigned int		i = 0;
	Contact					con;

	clearScreen();
	std::cout << "Contact's first name: ";
	con.setFirst(readInput(std::cin));
	std::cout << "Contact's last name: ";
	con.setLast(readInput(std::cin));
	std::cout << "Contact's nickname: ";
	con.setNick(readInput(std::cin));
	std::cout << "Contact's phone number: ";
	con.setNumber(readInput(std::cin));
	std::cout << "Contact's darkest secret: ";
	con.setSecret(readInput(std::cin));
	con.setIndex((i % 8) + 1);
	this->_contacts[i % 8] = con;
	if (i < 8)
		this->_len++;
	std::cout << "Contact added!" << std::endl;
	i++;
}

void	PhoneBook::search(void) {
	if (this->_len > 0) {
		clearScreen();
		std::cout << '\n';
		std::cout << "INDEX     |FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
		for ( const Contact &con : this->_contacts ) {
			if (con.is_filled())
				std::cout << std::right << std::setw(10) << con.getIndex() << '|'\
					<< std::right << std::setw(10) << con.truncate(con.getFirst()) << '|'\
					<< std::right << std::setw(10) << con.truncate(con.getLast()) << '|'\
					<< std::right << std::setw(10) << con.truncate(con.getNick()) << std::endl;
		}
		displayChoice();
	}
	else {
		clearScreen();
		std::cout << "\n###### CONTACTS LIST IS EMPTY ######\n" << std::endl;
		std::cout << "\nPress ENTER to continue ...\n" << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
}

void	PhoneBook::displayChoice(void) {
	std::stringstream	ss;
	int					index;
 
	while (1) {
		std::cout << std::endl;
		std::cout << "Please enter the index of the contact to display: ";
		this->_input = readInput(std::cin);
		ss.str("");
		ss.clear();
		ss << this->_input;
		ss >> index;
		if (isInRange(index)) {
			std::cout << "\nDISPLAYING CONTACT INFORMATION"  << std::endl;
			std::cout << "\tFirst Name: " << this->_contacts[index - 1].getFirst() << '\n'
			<< "\tLast Name: " << this->_contacts[index - 1].getLast() << '\n'
			<< "\tNickname: " << this->_contacts[index - 1].getNick() << '\n'
			<< "\tPhone Number: " << this->_contacts[index - 1].getNumber() << '\n'
			<< "\tDarkest Secret: " << this->_contacts[index - 1].getSecret() << '\n' << std::endl;
			std::cout << "\nPress ENTER to continue ...\n" << std::endl;
			std::getline(std::cin, this->_input);
			break ;
		}
	}
}

bool	PhoneBook::isInRange(int index) {
	if (index > 8 || index < 1 || index > this->_len) {
		std::cout << "Index out of range. Please enter a valid existing index (1-" \
					<< this->_len << ")." << std::endl;
		return false;
	}
	return true;
}

void	PhoneBook::exit(void) {
	this->_is_on = false;
}

static void	clearScreen(void) {
	std::cout << "\033[2J\033[1;1H";
}