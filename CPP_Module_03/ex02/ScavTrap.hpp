/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:58:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/19 23:06:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap  {
 
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(ScavTrap &copy);
  ScavTrap& operator=(const ScavTrap& copy);
  ~ScavTrap();

  void attack(const std::string& target);
  void guardGate();
};

#endif
