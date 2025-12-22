#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {
  public:
    // Orthodox Canonical Form
    Ice();
    ~Ice();
    Ice(const Ice &copy);
    // Ice& operator=(const Ice &copy);

    // Custom Constructors
    Ice(std::string const &type);
    
    // member functions
    Ice* clone() const;
    void use(ICharacter& target);
};

#endif
