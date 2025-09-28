/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:11:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/28 14:38:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack() const {
  std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name){
  _name = name;
  _weapon = NULL;
}

void HumanB::setWeapon(Weapon& wp)
{
  _weapon = &wp;
}

