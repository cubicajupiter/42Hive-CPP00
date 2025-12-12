/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:27:30 by jvalkama          #+#    #+#             */
/*   Updated: 2025/12/12 16:29:18 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <cctype>

class MegaPhone {
		std::string arg;
		std::string to_upper (std::string);
		void feedback (void);
		void scream (std::string);
	public:
		std::string input (char **);
		void amplify (std::string);
};

#endif
