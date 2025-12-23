#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define CSLOTS 4

class Character: public ICharacter {
  private:
    std::string _name;
    AMateria *_inventory[CSLOTS];
  public:
    // Orthodox Canonical Form
    Character();
    ~Character();
    Character(const Character &copy);
    Character& operator=(const Character &copy);

    // custom consructor
    Character(std::string const &name);
    

    // member functions
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
