#include "../includes/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <fstream>

// Constructors
PresidentialPardonForm::PresidentialPardonForm():
  AForm("PresidentialPardonForm", false, 25, 5), _target("unkonw"){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):
  AForm(copy),_target(copy._target){}
PresidentialPardonForm::PresidentialPardonForm(std::string target):
  AForm("PresidentialPardonForm", false, 25, 5), _target(target){}

// destructor
PresidentialPardonForm::~PresidentialPardonForm(){}
// CAO
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
  if (this != &copy)
  {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return (*this);
}

// memeber functions
void PresidentialPardonForm::execute(const Bureaucrat& obj) const 
{
  AForm::execute(obj);
}

void PresidentialPardonForm::executeAction() const
{
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
