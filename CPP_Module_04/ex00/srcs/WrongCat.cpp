#include "../includes/WrongCat.hpp"

// Constructors
WrongCat::WrongCat():WrongAnimal("WrongCat"){
  std::cout << "WrongCat default constructor '" << _type << "' called!" << std::endl;
};

WrongCat::WrongCat(std::string type): WrongAnimal(type){
  std::cout << "WrongCat Custom constructor '" << _type << "' called!" << std::endl;
}

WrongCat::WrongCat(WrongCat &copy): WrongAnimal(copy){
  std::cout << "WrongCat Copy Constructor '" << _type << "' called!" << std::endl;
}

// Operators Overloading - assignment  
WrongCat& WrongCat::operator=(WrongCat &copy)
{
  std::cout << "WrongCat Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  if (this != &copy)
    WrongAnimal::operator=(copy);
  return (*this);
}

WrongCat::~WrongCat(){
  std::cout << "WrongCat Destractor '" << _type << "' called!" << std::endl;
}

// member functions
void WrongCat::makeSound() const
{
  std::cout << "$ Wrong C🐱t's Bark $" << std::endl;
}

