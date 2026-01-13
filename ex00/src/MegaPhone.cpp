/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:13:07 by jvalkama          #+#    #+#             */
/*   Updated: 2025/12/13 12:35:00 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MegaPhone.hpp"

void	MegaPhone::use(char **av) {
	get_input(av);
	amplify();
}

void	MegaPhone::get_input(char **av) {
	int		i = 1;

	while (av[i]) {
		this->input += av[i];
		i++;
	}
	for ( i = 0; this->input[i]; i++ );
	this->str_len = i;
}

void	MegaPhone::amplify(void) {
	if (input.empty())
		feedback();
	else {
		output(capitalize());
	}
}

std::string	MegaPhone::capitalize(void) {
	std::string	result;

	result = this->input;
	for (char& c : result) {
		c = (static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
	}
	return (result);
}

void	MegaPhone::feedback(void) {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	MegaPhone::output(std::string str) {
	std::cout << str << std::endl;
}
