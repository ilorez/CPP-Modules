#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria {
  protected:
    std::string _type;
    AMaterias *_floor;
  public:
    // Orthodox Canonical Form
    AMateria();
    virtual ~AMateria();
    AMateria(const AMateria &copy);
    AMateria& operator=(const AMateria &copy);

    // Custom Constructors
    AMateria(std::string const &type);
    
    // member functions
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    // getters
    const std::string &getType() const;
    
  
};

#endif
