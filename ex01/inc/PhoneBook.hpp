#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <cstdint>
# include <array>

# include "Contact.hpp"

class PhoneBook {
	public:
			//constructor
		PhoneBook (void) 
			: is_on(false) {}
	private:
			//attributes
		std::array<Contact, 8>	contacts;
		bool					is_on;
		std::string				input;
		int						len = 0;
			//methods
		void		add (void);
		void		search (void);
		void		display_choice (void);
		bool		is_inrange (int);
		void		exit (void);
	public:
			//methods
		void		interface (void);
};

#endif
