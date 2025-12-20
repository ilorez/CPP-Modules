#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), _name("Default")
{
  _energy_points = 50;
  //_hit_points = 100;
  //_attack_damage = 30;

  // -> using Scope Resolution Operator

  //_hit_points = FragTrap::_hit_points;
  //_energy_points = ScavTrap::_energy_points;
  //_attack_damage = FragTrap::_attack_damage;
  std::cout << "DiamondTrap constructor called" << std::endl; 
} 

DiamondTrap::DiamondTrap(DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy) 
{
  std::cout << "DiamondTrap " << copy._name << ": copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name)
{
  _energy_points = 50;
  //_hit_points = 100;
  //_attack_damage = 30;

  // -> using Scope Resolution Operator
  //_hit_points = FragTrap::_hit_points;
  //_energy_points = ScavTrap::_energy_points; // the trick
  //_attack_damage = FragTrap::_attack_damage;
  std::cout << "DiamondTrap " << _name << ": custom constructor called" << std::endl;
  //std::cout << "Hit Point: " << _hit_points << std::endl;
  //std::cout << "ENergy Point: " << _energy_points << std::endl;
  //std::cout << "Attack damage: " << _attack_damage << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap " << _name << ": Destructor called" << std::endl;
}

// Assignment operator oveloading
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
  if (this != &copy)
  {
    _name = copy._name;
    ClapTrap::operator=(copy);
  }
  std::cout << "DiamondTrap " << _name << ": Copy assignment operator called" << std::endl;
  return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
  ScavTrap::attack(target);
}

// other member functions
void DiamondTrap::whoAmI(){
  std::cout << "DiamondTrap Name: " << _name << ", ClapTrap Name: " << ClapTrap::_name << "." << std::endl;
}

