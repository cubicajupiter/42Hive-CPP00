#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <cstdint>

class Contact {
	public:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_nbr;
		std::string		darkest_secret;
		unsigned int	index;
		bool			is_filled (void) const;
		std::string		truncate (const std::string&) const;
};

#endif