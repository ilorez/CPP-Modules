/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/19 23:17:28 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Constructors
ScavTrap::ScavTrap(): ClapTrap("default")
{
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
  std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
  std::cout << "ScavTrap " << copy._name << ": copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
  std::cout << "ScavTrap " << _name << ": custom constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap " << _name << ": Destructor called" << std::endl;
}

// Assignment operator oveloading
ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
  if (this != &copy)
    ClapTrap::operator=(copy);
  std::cout << "ScavTrap " << _name << ": Copy assignment operator called" << std::endl;
  return (*this);
}

// other member functions
void ScavTrap::attack(const std::string& target)
{
  if (_hit_points == 0)
  {
    std::cout << "ScavTrap " << _name << " already dead and can't attack!" << std::endl;
    return ;
  }
  if (_energy_points == 0)
  {
    std::cout << "ScavTrap " << _name << " have no energy points and can't attack!" << std::endl;
    return ;
  }
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "  <<  _attack_damage << " points of damage!" << std::endl;
  _energy_points--;
}

void ScavTrap::guardGate()
{
  std::cout <<  "ScavTrap " << _name << ": is now in Gate keeper mode!" << std::endl; 
}
