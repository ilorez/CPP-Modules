#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

// Constructors
AForm::AForm():
  _name("unkown"), 
  _is_signed(false),
  _req_grd_2signe(150),
  _req_grd_2exec(150)
{}

AForm::AForm(std::string name):
  _name(name),
  _is_signed(false),
  _req_grd_2signe(150),
  _req_grd_2exec(150)
{}
AForm::AForm(std::string name, bool s, int req_sgn, int req_exec):
  _name(name),
  _is_signed(s),
  _req_grd_2signe(req_sgn),
  _req_grd_2exec(req_exec)
{
  _gradeCheck(req_sgn);
  _gradeCheck(req_exec);
}
AForm::AForm(std::string name, int req_sgn, int req_exec):
  _name(name),
  _is_signed(false),
  _req_grd_2signe(req_sgn),
  _req_grd_2exec(req_exec)
{
  _gradeCheck(req_sgn);
  _gradeCheck(req_exec);
}
AForm::AForm(const AForm & copy):
  _name(copy._name),
  _is_signed(copy._is_signed),
  _req_grd_2signe(copy._req_grd_2signe),
  _req_grd_2exec(copy._req_grd_2exec)
{}

// copy assignment operator overloading 
AForm& AForm::operator=(const AForm& copy)
{
  if (this != &copy)
    this->_is_signed = copy._is_signed;
  return (*this);
}
// destructor
AForm::~AForm(){}

// member functions
void AForm::beSigned(const Bureaucrat& obj)
{
  if (_is_signed)
    throw AForm::AFormAlreadySignedException();
  else if (obj.getGrade() <= _req_grd_2signe)
    _is_signed = true;
  else
    throw  AForm::GradeTooLowException();
}


// getters
bool AForm::isSigned() const
{
  return (_is_signed);
}

int AForm::getRequiredGrade2Exec() const
{
  return (_req_grd_2exec);
}

int AForm::getRequiredGrade2Signe() const
{
  return (_req_grd_2signe);
}

const std::string& AForm::getName() const
{
  return (_name);
}

// excepitions
const char * AForm::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
};

const char * AForm::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
};

const char * AForm::AFormAlreadySignedException::what() const throw()
{
  return ("AForm already signed");
};

const char * AForm::AFormNotSignedException::what() const throw()
{
  return ("Not signed");
};

// operators ovloading
std::ostream& operator<<(std::ostream & os, const AForm & obj)
{
  std::string issigned = "not signed";
  if (obj.isSigned())
    issigned = "signed";
  os << obj.getName() << ", AForm is "<< issigned << ".";
  os << "(required grade to sign: " <<  obj.getRequiredGrade2Signe() << ",";
  os << "required grade to execute: " <<  obj.getRequiredGrade2Exec() << ")" ;
  return (os);
}

// private out of subject member functions
void AForm::_gradeCheck(int g) const
{
  if (g > 150)
    throw AForm::GradeTooLowException();
  if (g < 1)
    throw AForm::GradeTooHighException();
}

