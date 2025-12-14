#include "Contact.hpp"

bool    Contact::is_filled(void) const {
    if (first_name.empty())
        return false;
    return true;
}

std::string Contact::truncate(const std::string &field) const {
    if (field.length() > 10)
        return (field.substr(0, 9) + '.');
    return field;
}