/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:31:33 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/15 15:31:34 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook   phoneBook;

    for (Contact contact;;)
    {
        std::string in;

        std::cin >> in;
        if (in == "ADD")
        {
            std::cin >> contact;
            phoneBook.add(contact);
        }
        else if (in == "SEARCH")
            phoneBook.print_contacts();
        else if (in == "EXIT")
            return (0);
    }
}