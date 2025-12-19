/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/19 23:17:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


// Constructors
ClapTrap::ClapTrap(): _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
  std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
  std::cout << "ClapTrap " << copy._name << ": copy constructor called" << std::endl;
  *this = copy;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
  std::cout << "ClapTrap " << _name << ": custom constructor called" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap " << _name << ": Destructor called" << std::endl;
}

// Assignment operator oveloading
ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
  if (this != &copy)
  {
    _name = copy._name;
    _hit_points = copy._hit_points;
    _energy_points = copy._energy_points;
    _attack_damage = copy._attack_damage;
  }

  std::cout << "ClapTrap " << _name << ": Copy assignment operator called" << std::endl;
  return (*this);
}

// other member functions
void ClapTrap::attack(const std::string& target)
{
  if (_hit_points == 0)
  {
    std::cout << "ClapTrap " << _name << " already dead and can't attack!" << std::endl;
    return ;
  }
  if (_energy_points == 0)
  {
    std::cout << "ClapTrap " << _name << " have no energy points and can't attack!" << std::endl;
    return ;
  }
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "  <<  _attack_damage << " points of damage!" << std::endl;
  _energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (_hit_points <= 0)
  {
    std::cout << "ClapTrap " << _name << " already dead!" << std::endl;
    return;
  }
  if (_hit_points >= amount)
    _hit_points -= amount;
  else
    _hit_points = 0;
  std::cout << "ClapTrap " << this->_name << " takes " << amount << " amount of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (_hit_points == 0)
  {
    std::cout << "ClapTrap " << _name << " already dead and can't be Repaired!" << std::endl;
    return ;
  }
  if (_energy_points == 0)
  {
    std::cout << "ClapTrap " << _name << " have no energy points and can't be Repaired!!" << std::endl;
    return ;
  }
  _energy_points--;
  _hit_points += amount;
  std::cout << "ClapTrap " << this->_name << " repaired itself by " << amount << " amount of hit points, now its has " << _hit_points << " points!" << std::endl;
}
