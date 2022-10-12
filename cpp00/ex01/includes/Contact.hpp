/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:29:34 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/04 17:29:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Contact
{
public:
    Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);
    ~Contact();
    Contact operator=(const Contact& other);
    std::ostream& operator<<(std::ostream& os, const Contact& contact);
    std::istream& operator<<(std::istream& is, const Contact& contact);
    std::string get_first_name(void) const;
    std::string get_last_name(void) const;
    std::string get_nick_name(void) const;
    std::string get_phone_number(void) const;
    std::string get_darkest_secret(void) const;
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
};