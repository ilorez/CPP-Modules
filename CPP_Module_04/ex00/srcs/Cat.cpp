#include "../includes/Cat.hpp"

// Constructors
Cat::Cat():Animal("Cat"){
  std::cout << "Cat default constructor '" << _type << "' called!" << std::endl;
};

Cat::Cat(std::string type): Animal(type){
  std::cout << "Cat Custom constructor '" << _type << "' called!" << std::endl;
}

Cat::Cat(Cat &copy): Animal(copy){
  std::cout << "Cat Copy Constructor '" << _type << "' called!" << std::endl;
}

// Operators Overloading - assignment  
Cat& Cat::operator=(Cat &copy)
{
  std::cout << "Cat Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  if (this != &copy)
    Animal::operator=(copy);
  return (*this);
}

Cat::~Cat(){
  std::cout << "Cat Destractor '" << _type << "' called!" << std::endl;
}

// member functions
void Cat::makeSound() const
{
  std::cout << "$ C🐱t's Don't Bark $" << std::endl;
}

