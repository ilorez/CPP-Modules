
#include "../includes/Cure.hpp"

// constructors
Cure::Cure():AMateria("cure"){};
Cure::Cure(std::string const &type):AMateria(type){};
Cure::Cure(Cure const &copy):AMateria(copy){};

// assignment operator overloading 
// forbidden

// destructor
Cure::~Cure(){};


// member functions
Cure* Cure::clone() const
{
  return (new Cure(*this));
}


void Cure::use(ICharacter& target)
{
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
