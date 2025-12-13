/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:27:30 by jvalkama          #+#    #+#             */
/*   Updated: 2025/12/13 12:18:51 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <cctype>

class MegaPhone {
		std::string input;
		void capitalize (void);
		void get_input (char **);
		void amplify (void);
		void feedback (void);
		void output (void);
	public:
		void use (char **);

};

#endif
