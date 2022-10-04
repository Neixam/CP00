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

#ifndef CPP00_PHONEBOOK_HPP
#define CPP00_PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
public:
private:
    const Contact _contacts[8];
    int _size = 0;
};

#endif
