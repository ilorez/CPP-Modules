/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:53:52 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/29 15:41:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl(){};
Harl::~Harl(){};

void Harl::debug(void) {
  std::cout << "[ " << "DEBUG" << " ]" << std::endl;
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
            << std::endl << std::endl;
}

void Harl::info(void) {
  std::cout << "[ " << "INFO" << " ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
            << std::endl << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ " << "WARNING" << " ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
            << std::endl << std::endl;
}

void Harl::error(void) {
  std::cout << "[ " << "ERROR" << " ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now." 
            << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int i;
  for (i = 0; i < 4; i++)
    if (levels[i] == level)
      break;
  switch (i) {
    case 0:
      Harl::debug();
    case 1:
      Harl::info();
    case 2:
      Harl::warning();
    case 3:
      Harl::error();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
      break;
  }
}

