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
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook   phoneBook;
    std::string in;
    Contact     contact;
    int         index;

    for (;;)
    {
        std::cout << "Type command (ADD, SEARCH or EXIT): " << std::flush;
        if (!std::getline(std::cin, in))
            return (0);
        if (in == "ADD")
        {
            if (!(std::cin >> contact))
                return (0);
            phoneBook.add(contact);
        }
        else if (in == "SEARCH")
        {
            if (phoneBook.get_size() == 0)
            {
                std::cout << "No entry for this phone book" << std::endl;
                continue;
            }
            phoneBook.print_contacts();
            std::cout << "Give an index of contact: " << std::flush;
            std::cin >> index;
            if (!std::cin)
            {
                std::cout << "You must entry a number" << std::endl;
                return (0);
            }
            phoneBook.print_contact(index);
            std::cin.ignore();
        }
        else if (in == "EXIT")
            return (0);
        else if (!in.empty())
            std::cout << in << ": command doesn't exist" << std::endl;
    }
}