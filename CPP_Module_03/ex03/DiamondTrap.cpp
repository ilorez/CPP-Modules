#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(): ClapTrap("default")
{
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
  std::cout << "DiamondTrap constructor called" << std::endl; 
} 

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy)
{
  std::cout << "DiamondTrap " << copy._name << ": copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name)
{
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
  std::cout << "DiamondTrap " << _name << ": custom constructor called" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap " << _name << ": Destructor called" << std::endl;
}

// Assignment operator oveloading
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
  if (this != &copy)
    ClapTrap::operator=(copy);
  std::cout << "DiamondTrap " << _name << ": Copy assignment operator called" << std::endl;
  return (*this);
}

// other member functions
void DiamondTrap::whoAmI(){
  std::cout << _name << ClapTrap::_name << "." << std::endl;
}
