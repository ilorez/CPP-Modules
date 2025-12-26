
#include "../includes/Container.hpp"
#include <cstddef>


Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern & copy){*this=copy;}
Intern& Intern::operator=(const Intern & copy){
  (void)copy;
  return (*this);
}

AForm* createSCF(const std::string &target){return (new ShrubberyCreationForm(target));}
AForm* createRRF(const std::string &target){return (new RobotomyRequestForm(target));}
AForm* createPPF(const std::string &target){return (new PresidentialPardonForm(target));}

struct FormData {
  std::string name;
  AForm *(*create)(const std::string&);
};

AForm *Intern::makeForm(std::string form, std::string target) const
{
  FormData fd[] = {
    {"shrubbery creation", &createSCF},
    {"robotomy request", &createRRF},
    {"presidential pardon", &createPPF},
  };
  for (int i = 0; i < 3; i++)
  {
    if (fd[i].name == form)
    {
      std::cout << "Intern creates " << form << std::endl;
      return (fd[i].create(target));
    }
  }
  //throw Intern::FormNotFoundException();
  std::cerr << form << " form name not found" << std::endl;
  return (NULL);
}
