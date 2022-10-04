/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:29:02 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/04 09:29:04 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main(int ac, char **av)
{
    if (ac == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    else
    {
        for (int i = 1; i < ac; i++)
            for (int j = 0; av[i][j]; j++)
                cout << (char) toupper(av[i][j]);
        cout << endl;
    }
    return (0);
}