/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:53:52 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/28 17:11:06 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl(){};
Harl::~Harl(){};

void Harl::debug(void) {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
  void (Harl::*harlSay[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  bool found = false;
  should use switches

  for (int i = 0; i < 4 ; i++)
  {
    if (levels[i]  ==  level)
    {
      found = true;
      for (int j = i; j < 4 ; j++)
      {
          std::cout << "[ " << levels[j] << " ]" << std::endl;
          (this->*harlSay[j])();
          std::cout << std::endl;
      }
      break;
    }
  }
  if (!found)
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}






