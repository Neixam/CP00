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
#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook operator=(const PhoneBook& other);
    void add(Contact new_contact);
    void print_contacts(void);
    const Contact& search(int i);
    const Contact *get_contacts(void) const;
    int get_size(void) const;
private:
    Contact _contacts[8];
    int _size;
};