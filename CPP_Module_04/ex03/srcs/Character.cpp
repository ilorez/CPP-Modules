
#include "../includes/Character.hpp"
#include "../includes/Floor.hpp"
#include "../includes/Colors.hpp"
#include "../includes/Debug.hpp"
#include "Debug.hpp"

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
Character::~Character()
{
    for (int i = 0; i < CSLOTS; i++)
      if (_isSlotUsed[i])
        delete _inventory[i];
};


std::string const & Character::getName() const
{
  return (this->_name);
}

void Character::equip(AMateria* m)
{
  if (!m)
  {
      DEBUG_WARN(this->_name << " equip: null materia");
      return;
  }
  for (int i = 0; i < CSLOTS; i++)
  {
    if (!_isSlotUsed[i])
    {
      _inventory[i] = m;
      _isSlotUsed[i] = true;
      DEBUG_INFO(this->_name << " equipped materia type=" << m->getType());
      return;
    }
  }
  DEBUG_WARN(this->_name << " equip failed: inventory full");
}

void Character::unequip(int idx)
{
  if (idx < 0 || idx >= CSLOTS)
  {
    DEBUG_ERROR(this->_name << " unequip: invalid index");
    return;
  }
  if (!_isSlotUsed[idx])
  {
    DEBUG_WARN(this->_name << " unequip: slot already empty");
    return ;
  }

  Floor* tmp = new Floor; 
  tmp->value = _inventory[idx];
  tmp->next = floor;
  floor = tmp;
  _inventory[idx] = NULL;
  _isSlotUsed[idx] = false;
  DEBUG_INFO(this->_name << " unequipped slot " << idx);
}

void Character::use(int idx, ICharacter& target)
{
  if (idx < 0 || idx >= CSLOTS)
  {
    DEBUG_ERROR(" use: invalid index");
    return;
  }
  if (!_isSlotUsed[idx])
  {
    DEBUG_WARN(this->_name << " use: empty slot");
    return ;
  }
  _inventory[idx]->use(target);
  DEBUG_INFO(this->_name << " uses materia on " << target.getName());
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
