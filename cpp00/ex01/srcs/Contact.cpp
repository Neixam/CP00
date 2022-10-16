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
        << std::setw(10) << colonise(c.get_nick_name()) << "|"
        << std::setw(10) << colonise(c.get_phone_number()));
}

std::istream& operator>>(std::istream& is, Contact& contact)
{
    std::string fn;
    std::string ln;
    std::string nn;
    std::string pn;
    std::string ds;

    std::cout << "Enter a first name: " << std::flush;
    is >> fn;
    std::cout << "Enter a last name: " << std::flush;
    is >> ln;
    std::cout << "Enter a nick name: " << std::flush;
    is >> nn;
    std::cout << "Enter a phone number: " << std::flush;
    is >> pn;
    is.ignore();
    std::cout << "Enter your darkest secret: " << std::flush;
    do
        std::getline(is, ds);
    while (ds == "");
    contact.set_first_name(fn);
    contact.set_last_name(ln);
    contact.set_nick_name(nn);
    contact.set_phone_number(pn);
    contact.set_darkest_secret(ds);
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