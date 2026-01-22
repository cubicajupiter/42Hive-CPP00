/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:41:46 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/22 15:58:15 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool    Contact::is_filled(void) const {
    if (this->_first_name.empty())
        return false;
    return true;
}

std::string Contact::truncate(const std::string &field) const {
    if (field.length() > 10)
        return (field.substr(0, 9) + '.');
    return field;
}

void			Contact::setFirst (const std::string value) {
    this->_first_name = value;
}

void			Contact::setLast (const std::string value) {
    this->_last_name = value;
}

void			Contact::setNick (const std::string value) {
    this->_nickname = value;
}

void			Contact::setNumber (const std::string value) {
    this->_phone_nbr = value;
}

void			Contact::setSecret (const std::string value) {
    this->_darkest_secret = value;
}

void            Contact::setIndex (const int i) {
    this->_index = i;
}


const std::string&		Contact::getFirst (void) const {
    return this->_first_name;
}

const std::string&		Contact::getLast (void) const {
    return this->_last_name;
}
const std::string&		Contact::getNick (void) const {
    return this->_nickname;
}

const std::string&		Contact::getNumber (void) const {
    return this->_phone_nbr;
}

const std::string&		Contact::getSecret (void) const {
    return this->_darkest_secret;
}

int				        Contact::getIndex (void) const {
    return this->_index;
}