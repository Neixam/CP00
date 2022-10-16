/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:29:27 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/04 17:29:28 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

#ifndef DEBUG

Contact::Contact()
{
    this->_first_name = "";
    this->_last_name = "";
    this->_nick_name = "";
    this->_phone_number = "";
    this->_darkest_secret = "";
}

Contact::~Contact()
{
}

#else

Contact::Contact()
{
    std::cout << "Contact Constructor" << std::endl;
    this->_first_name = "";
    this->_last_name = "";
    this->_nick_name = "";
    this->_phone_number = "";
    this->_darkest_secret = "";
}

Contact::~Contact()
{
    std::cout << "Contact Destructor" << std::endl;
}
#endif

Contact Contact::operator=(const Contact& other)
{
    if (this == &other)
        return (*this);
    this->_first_name = other.get_first_name();
    this->_last_name = other.get_last_name();
    this->_nick_name = other.get_nick_name();
    this->_phone_number = other.get_phone_number();
    this->_darkest_secret = other.get_darkest_secret();
    return (*this);
}

std::string colonise(std::string cnt)
{
    if (cnt.size() > 10)
        return (cnt.substr(0, 9).append("."));
    return (cnt);
}

std::ostream& operator<<(std::ostream& os, const Contact& c)
{
    return (os << std::setw(10) << colonise(c.get_first_name()) << "|"
        << std::setw(10) << colonise(c.get_last_name()) << "|"
        << std::setw(10) << colonise(c.get_nick_name()));
}

std::istream& operator>>(std::istream& is, Contact& contact)
{
    static const struct
    {
        std::string fields;

        void (Contact::*setter)(std::string);
    }   setters[5] =
            {
                { "a first name", &Contact::set_first_name },
                { "a last name", &Contact::set_last_name },
                { "a nickname", &Contact::set_nick_name },
                { "a phone number", &Contact::set_phone_number },
                { "your darkest secret", &Contact::set_darkest_secret }
            };
    int i;

    is.ignore();
    for (i = 0; i < 5; i++)
    {
        std::string in;
        do
        {
            std::cout << "Enter " << setters[i].fields << ": " << std::flush;
            std::getline(is, in);
        } while (in == "");
        (contact.*setters[i].setter)(in);
    }
    return (is);
}

std::string Contact::get_first_name(void) const
{
    return (this->_first_name);
}

std::string Contact::get_last_name(void) const
{
    return (this->_last_name);
}

std::string Contact::get_nick_name(void) const
{
    return (this->_nick_name);
}

std::string Contact::get_phone_number(void) const
{
    return (this->_phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
    return (this->_darkest_secret);
}

void Contact::set_first_name(std::string fn)
{
    this->_first_name = fn;
}

void Contact::set_last_name(std::string ln)
{
    this->_last_name = ln;
}

void Contact::set_nick_name(std::string nn)
{
    this->_nick_name = nn;
}

void Contact::set_phone_number(std::string pn)
{
    this->_phone_number = pn;
}

void Contact::set_darkest_secret(std::string ds)
{
    this->_darkest_secret = ds;
}