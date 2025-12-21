#include "../includes/Cat.hpp"

// Constructors
Cat::Cat():Animal("Cat"){
  std::cout << "Cat default constructor '" << _type << "' called!" << std::endl;
  _brain = new Brain();
};

Cat::Cat(std::string type): Animal(type){
  std::cout << "Cat Custom constructor '" << _type << "' called!" << std::endl;
  _brain = new Brain();
}

Cat::Cat(Cat &copy): Animal(copy){
  std::cout << "Cat Copy Constructor '" << _type << "' called!" << std::endl;
  *this = copy;
}

// Operators Overloading - assignment  
Cat& Cat::operator=(Cat &copy)
{
  std::cout << "Cat Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  if (this != &copy)
  {
    Animal::operator=(copy);
    //delete _brain; // stupid line XD
    this->_brain = new Brain(*(copy._brain));
  }
  return (*this);
}

Cat::~Cat(){
  delete _brain;
  std::cout << "Cat Destractor '" << _type << "' called!" << std::endl;
}

// member functions
void Cat::makeSound() const
{
  std::cout << "$ C🐱t's Don't Bark $" << std::endl;
}

Brain* Cat::getBrain() const 
{
  return this->_brain;
}
