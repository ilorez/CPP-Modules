#include "../includes/AMateria.hpp"

// Constructors
AMateria::AMateria():_type("NoAnimal"){
};

AMateria::AMateria(std::string const &type): _type(type){}

AMateria::AMateria(const AMateria &copy){
  *this = copy;
}

// Operators Overloading - assignment  
AMateria& AMateria::operator=(const AMateria &copy)
{
  if (this != &copy)
  {
    //delete this;
    *this = *copy.clone();
  }
  return (*this);
}

// Destractor
AMateria::~AMateria(){}

// getters
const std::string& AMateria::getType() const
{
  return (this->_type);
}

// member fuctions
void AMateria::use(ICharacter& target){}

AMateria *ice = new Ice();
AMateria *cure = new Cure();
cure = ice;
