#include "../includes/Brain.hpp"

// Constructors
Brain::Brain(){
  std::cout << "Brain default constructor called!" << std::endl;
};


Brain::Brain(Brain &copy){
  *this = copy;
  std::cout << "Brain Copy Constructor called!" << std::endl;
}

// Operators Overloading - assignment  
Brain& Brain::operator=(Brain &copy)
{
  if (this != &copy)
  {
    for (int i = 0; i < BRAINSIZE ; i++)
      _ideas[i] = copy._ideas[i]; 
  }
  std::cout << "Brain Assignment OPO Constructors called!" << std::endl;
  return (*this);
}
// Destractor
Brain::~Brain(){
  std::cout << "Brain Destractor called!" << std::endl;
}

// getters and setters
void Brain::setIdea(int index, std::string value)
{
  _ideas[index] = value;
}

const std::string Brain::getIdea(int index) const
{
  return (_ideas[index]);
}

