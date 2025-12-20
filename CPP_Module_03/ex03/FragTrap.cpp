/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/20 16:19:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(): ClapTrap("default")
{
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
  std::cout << "FragTrap constructor called" << std::endl; } FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
  std::cout << "FragTrap " << copy._name << ": copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
  std::cout << "FragTrap " << _name << ": custom constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
  std::cout << "FragTrap " << _name << ": Destructor called" << std::endl;
}

// Assignment operator oveloading
FragTrap& FragTrap::operator=(const FragTrap& copy) {
  if (this != &copy)
    ClapTrap::operator=(copy);
  std::cout << "FragTrap " << _name << ": Copy assignment operator called" << std::endl;
  return (*this);
}


void FragTrap::highFivesGuys()
{
  std::cout <<  "FragTrap " << _name << ": send high-fives request!" << std::endl; 
}
