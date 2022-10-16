/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:25:24 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/04 17:25:25 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void    PhoneBook::add(Contact new_contact)
{
    if (this->_size != 8)
        this->_size++;
    for (int i = this->_size - 1; i > 0; i--)
        _contacts[i] = _contacts[i - 1];
    _contacts[0] = new_contact;
}

void    PhoneBook::print_contacts(void)
{
    for (int i = 0; i < _size; i++)
        std::cout << _contacts[i] << std::endl;
}


#ifndef DEBUG

PhoneBook::PhoneBook()
{
    this->_size = 0;
}

PhoneBook::~PhoneBook()
{
}

#else

PhoneBook::PhoneBook()
{
    this->_size = 0;
    std::cout << "PhoneBook Constructor" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook Destructor" << std::endl;
}
#endif

const Contact *PhoneBook::get_contacts(void) const
{
    return (_contacts);
}

int PhoneBook::get_size(void) const
{
    return (_size);
}

PhoneBook PhoneBook::operator=(const PhoneBook& other)
{
    if (this == &other)
        return (*this);
    for (int i = 0; i < other.get_size(); i++)
        this->_contacts[i] = other.get_contacts()[i];
    this->_size = other.get_size();
    return (*this);
}