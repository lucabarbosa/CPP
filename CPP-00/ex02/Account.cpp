/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:22:17 by lbento            #+#    #+#             */
/*   Updated: 2026/04/29 17:59:49 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cstddef>
// #include <iomanip>
#include <iostream>
#include <ctime>
#include "Account.hpp"

int   Account::_nbAccounts = 0;
int   Account::_totalAmount = 0;
int   Account::_totalNbDeposits = 0;
int   Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm		*local_time = std::localtime(&now);
	char		buffer[80];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local_time);
	std::cout << buffer;
}

void	Account::displayAccountsInfos(void)
{
   _displayTimestamp();
   std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
	 << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
   _displayTimestamp();
   std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
   _amount += deposit;
   _nbDeposits++;
   _totalNbDeposits++;
   _totalAmount += deposit;
   std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	total;
	
   _displayTimestamp();
   std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:";
	total = _amount - withdrawal;
   if (total < 0)
   {
       std::cout << "refused\n";
       return (false);
   }
   _nbWithdrawals++;
   _totalNbWithdrawals++;
   _amount -= withdrawal;
   _totalAmount -= withdrawal;
   std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
   return (true);
}
