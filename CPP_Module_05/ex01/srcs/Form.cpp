#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

// Constructors
Form::Form():
  _name("unkown"), 
  _is_signed(false),
  _req_grd_2signe(150),
  _req_grd_2exec(150)
{}

Form::Form(std::string name):
  _name(name),
  _is_signed(false),
  _req_grd_2signe(150),
  _req_grd_2exec(150)
{}
Form::Form(std::string name, bool s, int req_sgn, int req_exec):
  _name(name),
  _is_signed(s),
  _req_grd_2signe(req_sgn),
  _req_grd_2exec(req_exec)
{
  _gradeCheck(req_sgn);
  _gradeCheck(req_exec);
}
Form::Form(std::string name, int req_sgn, int req_exec):
  _name(name),
  _is_signed(false),
  _req_grd_2signe(req_sgn),
  _req_grd_2exec(req_exec)
{
  _gradeCheck(req_sgn);
  _gradeCheck(req_exec);
}
Form::Form(const Form & copy):
  _name(copy._name),
  _is_signed(copy._is_signed),
  _req_grd_2signe(copy._req_grd_2signe),
  _req_grd_2exec(copy._req_grd_2exec)
{}

// copy assignment operator overloading 
Form& Form::operator=(const Form& copy)
{
  if (this != &copy)
    this->_is_signed = copy._is_signed;
  return (*this);
}
// destructor
Form::~Form(){}

// member functions
void Form::beSigned(const Bureaucrat& obj)
{
  if (_is_signed)
    throw Form::FormALreadySignedException();
  else if (obj.getGrade() <= _req_grd_2signe)
    _is_signed = true;
  else
    throw  Form::GradeTooLowException();
}


// getters
bool Form::isSigned() const
{
  return (_is_signed);
}

int Form::getRequiredGrade2Exec() const
{
  return (_req_grd_2exec);
}

int Form::getRequiredGrade2Signe() const
{
  return (_req_grd_2signe);
}

const std::string& Form::getName() const
{
  return (_name);
}

// excepitions
const char * Form::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
};

const char * Form::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
};

const char * Form::FormALreadySignedException::what() const throw()
{
  return ("Form already signed");
};

// operators ovloading
std::ostream& operator<<(std::ostream & os, const Form & obj)
{
  std::string issigned = "not signed";
  if (obj.isSigned())
    issigned = "signed";
  os << obj.getName() << ", Form is "<< issigned << ".";
  os << "(required grade to sign: " <<  obj.getRequiredGrade2Signe() << ",";
  os << "required grade to execute: " <<  obj.getRequiredGrade2Exec() << ")" ;
  return (os);
}

// private out of subject member functions
void Form::_gradeCheck(int g) const
{
  if (g > 150)
    throw Form::GradeTooLowException();
  if (g < 1)
    throw Form::GradeTooHighException();
}

