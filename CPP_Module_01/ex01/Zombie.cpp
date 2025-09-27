/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:23:44 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/27 23:04:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void Zombie::announce(void) const
{
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
  std::cout << getZombieName() << ": Has Destroyed" << std::endl;
}

Zombie::Zombie(){}

void Zombie::setZombieName(std::string value)
{
  _name = value;
}

std::string Zombie::getZombieName(void) const {
  return (_name);
}
