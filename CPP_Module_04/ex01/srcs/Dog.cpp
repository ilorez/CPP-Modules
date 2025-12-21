#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

// Constructors
Dog::Dog():Animal("Dog"){
  _brain = new Brain();
  std::cout << "Dog default constructor '" << _type << "' called!" << std::endl;
};

Dog::Dog(std::string type): Animal(type){
  _brain = new Brain();
  std::cout << "Dog Custom constructor '" << _type << "' called!" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy){
  this->_brain = new Brain(*copy._brain);
  std::cout << "Dog Copy Constructor '" << _type << "' called!" << std::endl;
}

// Operators Overloading - assignment  
Dog& Dog::operator=(const Dog &copy)
{
  if (this != &copy)
  {
    Animal::operator=(copy);
    delete this->_brain;
    this->_brain = new Brain(*copy._brain);
  }
  std::cout << "Dog Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  return (*this);
}

Dog::~Dog(){
  delete _brain;
  std::cout << "Dog Destractor '" << _type << "' called!" << std::endl;
}

// member functions
void Dog::makeSound() const
{
  std::cout << "$ D🐶g's Don't Meow $" << std::endl;
}

Brain* Dog::getBrain() const 
{
  return this->_brain;
}
