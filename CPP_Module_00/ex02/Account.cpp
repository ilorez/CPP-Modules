/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:07:21 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/26 17:02:58 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
/*

*/



int Account::_nbAccounts = 0;
int Account::_totalAmount = 0; int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
  _nbDeposits = 0;
  //if (initial_deposit)
  //{
  //  _nbDeposits = 1;
  //  _totalNbDeposits += 1;
  //}
  _amount = initial_deposit;
  _nbWithdrawals = 0;
  _accountIndex = _nbAccounts;
  _nbAccounts++;
  _totalAmount += initial_deposit;
  std::cout << "index:"<< _accountIndex << ";amount:"<< _amount << ";created" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
  std::cout << "accounts:" << getNbAccounts() 
            << ";total:" << getTotalAmount() 
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals()
            << std::endl;
}

// log that it's closed
Account::~Account()
{
  std::cout <<  "index:" << _accountIndex
            << ";amount:" << _amount 
            << ";closed" 
            << std::endl;
}

void	Account::displayStatus( void ) const 
{
  std::cout <<  "index:" << _accountIndex
            << ";amount:" << _amount 
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals
            << std::endl;
} 

void	Account::makeDeposit( int deposit ){

  std::cout <<  "index:" << _accountIndex
            << ";p_amount:" << _amount 
            << ";deposit:" << deposit;
  _amount += deposit;
  _nbDeposits += 1;
  std::cout <<  ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits 
            << std::endl;
  _totalNbDeposits += 1;
  _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
  std::cout << "index:" << _accountIndex 
            << ";p_amount:" << _amount; 
  if (withdrawal < 0 || withdrawal > _amount)
  {
    std::cout << ";withdrawal:refused" << std::endl;
    return (false);
  }
  _amount -= withdrawal;
  _nbWithdrawals += 1;
  std::cout << ";withdrawal:" << withdrawal
            << ";amount:" << _amount
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

