/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:27:17 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/04 17:27:22 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook(const PhoneBook& phoneBook);
    PhoneBook&      operator=(const PhoneBook& other);
    void            add(const Contact& new_contact);
    void            print_contacts(void);
    const Contact   *get_contacts(void) const;
    void            print_contact(int index);
    int             get_size(void) const;
private:
    Contact _contacts[8];
    int     _size;
};
#endif