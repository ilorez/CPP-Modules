#include "../includes/WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal():_type("NoAnimal"){
  std::cout << "WrongAnimal default constructor '" << _type << "' called!" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type): _type(type){
  std::cout << "WrongAnimal Custom constructor '" << _type << "' called!" << std::endl;
}


WrongAnimal::WrongAnimal(WrongAnimal &copy){
  *this = copy;
  std::cout << "WrongAnimal Copy Constructor '" << _type << "' called!" << std::endl;
}

// Operators Overloading - assignment  
WrongAnimal& WrongAnimal::operator=(WrongAnimal &copy)
{
  if (this != &copy)
  {
    this->_type = copy._type;
  }
  std::cout << "WrongAnimal Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  return (*this);
}
// Destractor
WrongAnimal::~WrongAnimal(){
  std::cout << "WrongAnimal Destractor '" << _type << "' called!" << std::endl;
}

// member functions
void WrongAnimal::makeSound() const
{
  std::cout << "$ WrongAnimal: what is wrong sound ? $" << std::endl;
}

// getters
const std::string WrongAnimal::getType() const
{
  return (this->_type);
}
