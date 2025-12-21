#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

// Constructors
Dog::Dog():Animal("Dog"){
  std::cout << "Dog default constructor '" << _type << "' called!" << std::endl;
  _brain = new Brain();
};

Dog::Dog(std::string type): Animal(type){
  std::cout << "Dog Custom constructor '" << _type << "' called!" << std::endl;
  _brain = new Brain();
}

Dog::Dog(Dog &copy): Animal(copy){
  std::cout << "Dog Copy Constructor '" << _type << "' called!" << std::endl;
  *this = copy;
}

// Operators Overloading - assignment  
Dog& Dog::operator=(Dog &copy)
{
  std::cout << "Dog Assignment OPO Constructors '" << _type << "' called!" << std::endl;
  if (this != &copy)
  {
    Animal::operator=(copy);
    delete _brain;
    this->_brain = new Brain(*copy._brain);
  }
  return (*this);
}

Dog::~Dog(){
  std::cout << "Dog Destractor '" << _type << "' called!" << std::endl;
  delete _brain;
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
