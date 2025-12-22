#include "../includes/AMateria.hpp"

// Constructors
AMateria::AMateria():_type("NoAnimal"){
};

AMateria::AMateria(std::string const &type): _type(type){}

AMateria::AMateria(const AMateria &copy):_type(copy._type){}

// Destractor
AMateria::~AMateria(){}

// getters
const std::string& AMateria::getType() const
{
  return (this->_type);
}

// member fuctions
void AMateria::use(ICharacter& target){(void) target;}

//AMateria *ice = new Ice();
//AMateria *cure = new Cure();
//cure = ice;
