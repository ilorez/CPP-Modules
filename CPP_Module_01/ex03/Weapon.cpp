/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:35:29 by znajdaou          #+#    #+#             */
/*   Updated: 2025/11/07 15:22:35 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

void Weapon::setType(std::string type)
{
  _type = type;
}

Weapon::Weapon(std::string type):_type(type){};

const std::string& Weapon::getType(void) const
{
  return (_type);
}


Weapon::Weapon(){};


