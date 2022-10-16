/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:44:30 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/16 15:44:32 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include "Account.hpp"
#include "../includes/Account.hpp"

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
        << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

Account::Account(int initial_deposit)
{
    _nbDeposits = 0;
    _amount = initial_deposit;
    _accountIndex = Account::_nbAccounts++;
    _nbWithdrawals = 0;
    Account::_totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    Account::_nbAccounts--;
    Account::_totalNbDeposits -= _nbDeposits;
    Account::_totalNbWithdrawals -= _nbWithdrawals;
    _totalAmount -= _amount;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    char buffer[18];
    std::time_t tt = std::time(NULL);

    strftime(buffer, 18, "[%Y%m%d_%H%M%S]", std::localtime(&tt));
    std::cout << buffer;
}

Account::Account(void)
{
    _accountIndex = Account::_nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}