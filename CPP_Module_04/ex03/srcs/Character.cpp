
#include "../includes/Character.hpp"
#include "../includes/Floor.hpp"
#include "../includes/Colors.hpp"

static Floor* floor;
// constructors
Character::Character():ICharacter(){
    for (int i = 0; i < CSLOTS; i++)
        _isSlotUsed[i] = 0;
};
Character::Character(Character const &copy){
  *this = copy;
};

// custom constructor
Character::Character(std::string const &name):_name(name){}

// assignment operator overloading 
Character& Character::operator=(Character const &copy)
{
  if (&copy != this)
  {
    for (int i = 0; i < CSLOTS; i++)
    {
      if (_isSlotUsed[i])
      {
        delete _inventory[i];
        _isSlotUsed[i] = copy._isSlotUsed[i];
        if (_isSlotUsed[i])
          _inventory[i] = copy._inventory[i]->clone();
        else
          _inventory[i] = NULL;
      }
    }
    this->_name = copy._name;
  }
  return (*this);
}

// destructor
Character::~Character(){};


std::string const & Character::getName() const
{
  return (this->_name);
}
void Character::equip(AMateria* m)
{
  for (int i = 0; i < CSLOTS; i++)
  {
    if (!_isSlotUsed[i])
    {
      _inventory[i] = m;
      _isSlotUsed[i] = true;
      return;
    }
  }
}

void Character::unequip(int idx)
{
  if (idx < 0 || idx >= CSLOTS)
  {
    std::cerr << ERROR_MSG << this->_name << " unequip: invalid index" << std::endl;
    return;
  }
  if (!_isSlotUsed[idx])
  {
    std::cerr << WARNING_MSG << this->_name << " unequip: slot is empty" << std::endl;
    return ;
  }

  Floor* tmp = new Floor; 
  tmp->value = _inventory[idx];
  tmp->next = floor;
  floor = tmp;
  _inventory[idx] = NULL;
  _isSlotUsed[idx] = false;
}

void Character::use(int idx, ICharacter& target)
{
  if (idx < 0 || idx >= CSLOTS)
  {
    std::cerr << ERROR_MSG << this->_name << " use: invalid index" << std::endl;
    return;
  }
  if (!_isSlotUsed[idx])
  {
    std::cerr << WARNING_MSG << this->_name << " use: slot is empty" << std::endl;
    return ;
  }
  _inventory[idx]->use(target);
}

// floor
void clearFloor() {
    while (floor) {
        Floor* tmp = floor;
        floor = floor->next;
        delete tmp->value;
        delete tmp;
    }
}
