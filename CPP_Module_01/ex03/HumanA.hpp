/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:12:07 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/28 14:32:25 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include "Weapon.hpp"

class HumanA {
public:
  std::string _name;
  Weapon& _weapon;
  HumanA(std::string name, Weapon& weapon):_name(name), _weapon(weapon){}
  void attack() const;
};
#endif
