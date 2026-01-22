/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:45:53 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/22 15:58:14 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <limits>
# include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook (void) : _is_on(false) {}

	private:
		Contact					_contacts[8];
		bool					_is_on;
		std::string				_input;
		int						_len = 0;

		void		add (void);
		void		search (void);
		void		displayChoice (void);
		bool		isInRange (int);
		void		exit (void);

	public:
		void		interface (void);

};
