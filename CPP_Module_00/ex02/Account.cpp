/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:07:21 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/26 18:41:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
  _nbDeposits = 0;
  _amount = initial_deposit;
  _nbWithdrawals = 0;
  _accountIndex = getNbAccounts();
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << "index:"<< _accountIndex << ";amount:"<< _amount << ";created" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() 
            << ";total:" << getTotalAmount() 
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals()
            << std::endl;
}

// log that it's closed
Account::~Account()
{
  _displayTimestamp();
  std::cout <<  "index:" << _accountIndex
            << ";amount:" << checkAmount() 
            << ";closed" 
            << std::endl;
}

void	Account::displayStatus( void ) const 
{
  _displayTimestamp();
  std::cout <<  "index:" << _accountIndex
            << ";amount:" << checkAmount() 
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals
            << std::endl;
} 

void	Account::makeDeposit( int deposit ){

  _displayTimestamp();
  std::cout <<  "index:" << _accountIndex
            << ";p_amount:" << checkAmount() 
            << ";deposit:" << deposit;
  _amount += deposit;
  _nbDeposits += 1;
  std::cout <<  ";amount:" << checkAmount()
            << ";nb_deposits:" << _nbDeposits 
            << std::endl;
  _totalNbDeposits += 1;
  _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex 
            << ";p_amount:" << checkAmount(); 
  if (withdrawal < 0 || withdrawal > checkAmount())
  {
    std::cout << ";withdrawal:refused" << std::endl;
    return (false);
  }
  _amount -= withdrawal;
  _nbWithdrawals += 1;
  std::cout << ";withdrawal:" << withdrawal
            << ";amount:" << checkAmount()
            << ";nb_withdrawals:" << _nbWithdrawals
            << std::endl;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals += 1;
  return (true);
}

int		Account::checkAmount( void ) const
{
  return (_amount);
}

int	Account::getNbAccounts( void )
{
  return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
  return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
  return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
  return (_totalNbWithdrawals);
}

// [19920104_091532]
void	Account::_displayTimestamp( void ){
  time_t now = time(0);
  struct tm *local = localtime(&now);
  std::cout << "[" << 1900 + local->tm_year
            << std::setfill('0') << std::setw(2) << 1 + local->tm_mon
            << std::setfill('0') << std::setw(2) << local->tm_mday << "_"
            << std::setfill('0') << std::setw(2) << local->tm_hour
            << std::setfill('0') << std::setw(2) << local->tm_min
            << std::setfill('0') << std::setw(2) << local->tm_sec << "] ";
}
