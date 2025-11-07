/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:23:44 by znajdaou          #+#    #+#             */
/*   Updated: 2025/11/07 15:18:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"


Zombie::Zombie(std::string name):_name(name){};

void Zombie::announce(void) const
{
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
  std::cout << _name << ": Has Destroyed" << std::endl;
}

Zombie::Zombie(){}

void Zombie::setZombieName(std::string value)
{
  _name = value;
}

std::string Zombie::getZombieName(void) const {
  return (_name);
}
