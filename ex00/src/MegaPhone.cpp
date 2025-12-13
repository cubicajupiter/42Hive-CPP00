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

	while (av[i])
		input += av[i++];
}

void	MegaPhone::amplify(void) {
	if (input.empty())
		feedback();
	else {
		capitalize();
		output();
	}
}

void	MegaPhone::capitalize(void) {
	std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
		return std::toupper(c);
	});
}

void	MegaPhone::feedback(void) {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	MegaPhone::output(void) {
	std::cout << input << std::endl;
}
