#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <fstream>

// Constructors
RobotomyRequestForm::RobotomyRequestForm():
  AForm("RobotomyRequestForm", false, 72, 45), _target("unkonw"){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):
  AForm(copy),_target(copy._target){}
RobotomyRequestForm::RobotomyRequestForm(std::string target):
  AForm("RobotomyRequestForm", false, 72, 45), _target(target){}

// destructor
RobotomyRequestForm::~RobotomyRequestForm(){}
// CAO
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
  if (this != &copy)
  {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return (*this);
}

// memeber functions
void RobotomyRequestForm::execute(const Bureaucrat& obj) const 
{
  AForm::execute(obj);
}

void RobotomyRequestForm::executeAction() const
{
  std::cout << "aaawwwwooouuuugh" << std::endl; 
  if (std::rand() % 2)
    std::cout << this->_target << "has been robotomized successfully" << std::endl;
  else
    std::cout << _target << " robotomy failed." << std::endl;
}
