#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm():
  AForm("ShrubberyCreationForm", false, 145, 137), _target("unkonw"){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
  AForm(copy),_target(copy._target){}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
  AForm("ShrubberyCreationForm", false, 145, 137), _target(target){}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm(){}
// CAO
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
  if (this != &copy)
  {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return (*this);
}

// Execeptions
const char* ShrubberyCreationForm::ShrubberyCreationFormFileNotOpenException::what() const throw()
{
  return ("Couldn't open file");
}

// memeber functions
void ShrubberyCreationForm::execute(const Bureaucrat& obj) const 
{
  AForm::execute(obj);
}

void ShrubberyCreationForm::executeAction() const
{
  std::ofstream writeFile((_target+"_shrubbery").c_str());
  if (!writeFile.is_open())
    throw ShrubberyCreationFormFileNotOpenException();
  //  writeFile << "tree";
  writeFile << "\n\
       _-_\n\
    /~~   ~~\\\n\
 /~~         ~~\\\n\
{               }\n\
 \\  _-     -_  /\n\
   ~  \\\\ //  ~\n\
_- -   | | _- _\n\
  _ -  | |   -_\n\
      // \\\\\n\
     //   \\\\" << std::endl << "Tree" << std::endl;

  writeFile.close();
}
