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

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number,
                 std::string darkest_secret)
{
    this._first_name = first_name;
    this._last_name = last_name;
    this._nick_name = nick_name;
    this._phone_number = phone_number;
    this._darkest_secret = darkest_secret;
}

Contact::~Contact()
{
    delete this._first_name;
    delete this._last_name;
    delete this._nick_name;
    delete this._phone_number;
    delete this._darkest_secret;
}

Contact Contact::operator=(const Contact& other)
{
    return (new Contact(other.get_first_name(), other.get_last_name(), other.get_nick_name(), other.get_phone_number(),
                other.get_darkest_secret));
}

std::ostream& Contact::operator<<(std::ostream& os, const Contact& contact)
{
    os << contact.get_first_name() << " | ";
    os << contact.get_last_name() << " | ";
    os << contact.get_nick_name() << " | ";
    os << contact.get_phone_number();
    return (os);
}

std::istream& Contact::operator>>(std::istream& is, const Contact& contact)
{
    contact <<
}