
#include "../includes/Ice.hpp"

// constructors
Ice::Ice():AMateria("ice"){};
Ice::Ice(std::string const &type):AMateria(type){};
Ice::Ice(Ice const &copy):AMateria(copy){};

// assignment operator overloading 
// forbidden

// destructor
Ice::~Ice(){};


// member functions
Ice* Ice::clone() const
{
  return (new Ice(*this));
}


void Ice::use(ICharacter& target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
