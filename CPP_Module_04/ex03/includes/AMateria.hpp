#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "iostream"
class ICharacter;

class AMateria {
  protected:
    std::string _type;
  public:
    // Orthodox Canonical Form
    AMateria();
    virtual ~AMateria();
    AMateria(const AMateria &copy);

    // Custom Constructors
    AMateria(std::string const &type);
    
    // member functions
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    // getters
    const std::string &getType() const;

  private:
    AMateria& operator=(const AMateria &copy);
};

#endif
