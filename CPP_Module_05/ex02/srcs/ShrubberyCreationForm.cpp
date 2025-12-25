#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():AForm(), _target("unkonw"){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
  AForm(copy),
  _target(copy._target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm(), _target(target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
  if (this != &copy)
  {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return (*this);
}

const char* ShrubberyCreationForm::ShrubberyCreationFormFileNotOpenException::what() const throw()
{
  return ("Couldn't open file");

}

void ShrubberyCreationForm::execute(const Bureaucrat& obj) const 
{
  if (!isSigned())
    throw AForm::AFormNotSignedException();
  if (obj.getGrade() > this->getRequiredGrade2Exec())
    throw AForm::GradeTooLowException();
  std::ofstream writeFile((_target+"_shrubbery").c_str());
  if (!writeFile.is_open())
    throw ShrubberyCreationFormFileNotOpenException();
  writeFile << "tree";
/*
  writeFile << R"(

              _{\ _{\{\/}/}/}__
             {/{/\}{/{/\}(\}{/\} _
            {/{/\}{/{/\}(_)\}{/{/\}  _
         {\{/(\}\}{/{/\}\}{/){/\}\} /\}
        {/{/(_)/}{\{/)\}{\(_){/}/}/}/}
       _{\{/{/{\{/{/(_)/}/}/}{\(/}/}/}
      {/{/{\{\{\(/}{\{\/}/}{\}(_){\/}\}
      _{\{/{\{/(_)\}/}{/{/{/\}\})\}{/\}
     {/{/{\{\(/}{/{\{\{\/})/}{\(_)/}/}\}
      {\{\/}(_){\{\{\/}/}(_){\/}{\/}/})/}
       {/{\{\/}{/{\{\{\/}/}{\{\/}/}\}(_)
      {/{\{\/}{/){\{\{\/}/}{\{\(/}/}\}/}
       {/{\{\/}(_){\{\{\(/}/}{\(_)/}/}\}
         {/({/{\{/{\{\/}(_){\/}/}\}/}(\}
          (_){/{\/}{\{\/}/}{\{\)/}/}(_)
            {/{/{\{\/}{/{\{\{\(_)/}
             {/{\{\{\/}/}{\{\\}/}
              {){/ {\/}{\/} \}\}
              (_)  \.-'.-/
          __...--- |'-.-'| --...__
   _...--"   .-'   |'-.-'|  ' -.  ""--..__
 -"    ' .  . '    |.'-._| '  . .  '   jro
 .  '-  '    .--'  | '-.'|    .  '  . '
          ' ..     |'-_.-|
  .  '  .       _.-|-._ -|-._  .  '  .
              .'   |'- .-|   '.
  ..-'   ' .  '.   `-._.-`   .'  '  - .
   .-' '        '-._______.-'     '  .
        .      ~,
    .       .   |\   .    ' '-.
    ___________/  \____________
   /  Why is it, when you want \
  |  something, it is so damn   |
  |    much work to get it?     |
   \___________________________/

)";
  */
  writeFile.close();
}


