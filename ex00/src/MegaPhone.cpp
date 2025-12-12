/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:13:07 by jvalkama          #+#    #+#             */
/*   Updated: 2025/12/12 16:29:29 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MegaPhone.hpp"

void	MegaPhone::amplify(std::string input) {
	if (arg.empty())
		feedback();
	else
		scream(arg);
}

std::string	MegaPhone::input(char **av) {
	int		i = 1;

	while (av[i])
		arg + av[i++];
}

std::string	MegaPhone::to_upper(std::string arg) {
	std::transform(arg.begin(), arg.end(), arg.begin(), [](unsigned char c) {
		return std::toupper(c);
	});
	return arg;
}

void	MegaPhone::feedback(void) {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	MegaPhone::scream(std::string input) {
	std::cout << to_upper(input) << std::endl;
}
