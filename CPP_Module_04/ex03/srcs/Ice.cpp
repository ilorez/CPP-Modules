
#include "../includes/Ice.hpp"

// constructors
Ice::Ice():AMateria("ice"){};
Ice::Ice(std::string const &type):AMateria(type){};
Ice::Ice(Ice const &copy){
  *this = copy;
};
// assignment operator overloading 
Ice& Ice::operator=(Ice const &copy)
{
  if (&copy != this)
  {
    AMateria::operator=(copy);
  }
  return (*this);
}
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
