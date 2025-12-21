#include "../includes/Brain.hpp"

// Constructors
Brain::Brain(){
  std::cout << "Brain default constructor called!" << std::endl;
};


Brain::Brain(const Brain &copy){
  *this = copy;
  std::cout << "Brain Copy Constructor called!" << std::endl;
}

// Operators Overloading - assignment  
Brain& Brain::operator=(const Brain &copy)
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
void Brain::setIdea(int index, std::string &value)
{
  if (index < 0 || index >= BRAINSIZE)
  {
    std::cout << "You can't get idea, the index: " << index << " is out of range!" << std::endl;
    return;
  }
  _ideas[index] = value;
}

const std::string Brain::getIdea(int index) const
{
  if (index < 0 || index >= BRAINSIZE)
  {
    std::cout << "You can't get idea, the index: " << index << " is out of range!" << std::endl;
    return "";
  }
  return (_ideas[index]);
}

