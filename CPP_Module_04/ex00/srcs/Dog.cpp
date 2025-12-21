#include "../includes/Dog.hpp"

// Constructors
Dog::Dog():Animal("Dog"){
  std::cout << "Dog default constructor '" << _type << "' called!" << std::endl;
};

Dog::Dog(std::string type): Animal(type){
  std::cout << "Dog Custom constructor '" << _type << "' called!" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy){
  std::cout << "Dog Copy Constructor '" << _type << "' called!" << std::endl;
}

// Operators Overloading - assignment  
Dog& Dog::operator=(const Dog &copy)
{
  if (this != &copy)
    Animal::operator=(copy);
  std::cout << "Dog Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  return (*this);
}

Dog::~Dog(){
  std::cout << "Dog Destractor '" << _type << "' called!" << std::endl;
}

// member functions
void Dog::makeSound() const
{
  std::cout << "$ D🐶g's Don't Meow $" << std::endl;
}


