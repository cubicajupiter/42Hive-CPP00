/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:41:43 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/22 15:58:14 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <cstdint>

class Contact {

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_nbr;
		std::string		_darkest_secret;
		unsigned int	_index;

	public:
		bool			is_filled (void) const;
		std::string		truncate (const std::string&) const;
		void			setFirst (const std::string);
		void			setLast (const std::string);
		void			setNick (const std::string);
		void			setNumber (const std::string);
		void			setSecret (const std::string);
		void			setIndex (const int);
		const std::string&		getFirst (void) const;
		const std::string&		getLast (void) const;
		const std::string&		getNick (void) const;
		const std::string&		getNumber (void) const;
		const std::string&		getSecret (void) const;
		int				getIndex (void) const;


};