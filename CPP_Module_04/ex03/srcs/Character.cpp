
#include "../includes/Character.hpp"
#include "../includes/Floor.hpp"

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
        delete _slots[i];
        _isSlotUsed[i] = copy._isSlotUsed[i];
        if (_isSlotUsed[i])
          _slots[i] = copy._slots[i]->clone();
        else
          _slots[i] = NULL;
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
      _slots[i] = m;
      _isSlotUsed[i] = true;
      return;
    }
  }
}

void Character::unequip(int idx)
{
  if (idx < 0 || idx >= CSLOTS)
  {
    std::cout << this->_name << " unequip: invalid index" << std::endl;
    return;
  }
  if (!_isSlotUsed[idx])
  {
    std::cout << this->_name << " unequip: slot is empty" << std::endl;
    return ;
  }

  Floor* tmp = new Floor; 
  tmp->value = _slots[idx];
  tmp->next = floor;
  floor = tmp;
  _slots[idx] = NULL;
  _isSlotUsed[idx] = false;
}

void Character::use(int idx, ICharacter& target)
{
  if (idx < 0 || idx >= CSLOTS)
  {
    std::cout << this->_name << " use: invalid index" << std::endl;
    return;
  }
  if (!_isSlotUsed[idx])
  {
    std::cout << this->_name << " use: slot is empty" << std::endl;
    return ;
  }
  _slots[idx]->use(target);
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
