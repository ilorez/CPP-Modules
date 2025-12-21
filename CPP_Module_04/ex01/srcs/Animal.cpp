#include "../includes/Animal.hpp"

// Constructors
Animal::Animal():_type("NoAnimal"){
  std::cout << "Animal default constructor '" << _type << "' called!" << std::endl;
};

Animal::Animal(std::string type): _type(type){
  std::cout << "Animal Custom constructor '" << _type << "' called!" << std::endl;
}


Animal::Animal(const Animal &copy){
  *this = copy;
  std::cout << "Animal Copy Constructor '" << _type << "' called!" << std::endl;
}

// Operators Overloading - assignment  
Animal& Animal::operator=(const Animal &copy)
{
  if (this != &copy)
  {
    this->_type = copy._type;
  }
  std::cout << "Animal Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  return (*this);
}

// Destractor
Animal::~Animal(){
  std::cout << "Animal Destractor '" << _type << "' called!" << std::endl;
}

// member functions
void Animal::makeSound() const
{
  std::cout << "$ Animal: what is sound ? $" << std::endl;
}

// getters
const std::string Animal::getType() const
{
  return (this->_type);
}
