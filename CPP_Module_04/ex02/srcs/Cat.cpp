#include "../includes/Cat.hpp"

// Constructors
Cat::Cat():Animal("Cat"){
  _brain = new Brain();
  std::cout << "Cat default constructor '" << _type << "' called!" << std::endl;
};

Cat::Cat(std::string type): Animal(type){
  _brain = new Brain();
  std::cout << "Cat Custom constructor '" << _type << "' called!" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy){
  this->_brain = new Brain(*(copy._brain));
  std::cout << "Cat Copy Constructor '" << _type << "' called!" << std::endl;
}

// Operators Overloading - assignment  
Cat& Cat::operator=(const Cat &copy)
{
  if (this != &copy)
  {
    Animal::operator=(copy);
    delete this->_brain;
    this->_brain = new Brain(*(copy._brain));
  }
  std::cout << "Cat Assignment OPO Constructors '" << _type << "' called!" << std::endl;
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
