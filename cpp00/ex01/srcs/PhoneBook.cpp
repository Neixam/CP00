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
    if (this._size != 8)
        this._size++;
    for (int i = this._size - 1; i > 0; i--)
        this._contacts[i] = this._contacts[i - 1];
    this._contatcs[0] = new_contact;
}

void    PhoneBook::print_contacts(void)
{
    for (int i = 0; i < this._size; i++)
        std::cout << this._contacts[i] << std::endl;
}

PhoneBook::PhoneBook()
{
    std::cout << "PhoneBook Constructor" << std::endl
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook Destructor" << std::endl
}