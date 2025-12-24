
#include "../includes/Bureaucrat.hpp"
#include <ostream>

// Constructors
Bureaucrat::Bureaucrat():_name("unkown"), _grade(150){}
Bureaucrat::Bureaucrat(std::string name):_name(name), _grade(150){}
Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
{
  if (_grade > 150)
    throw Bureaucrat::GradeTooLowException();
  if (_grade < 1)
    throw Bureaucrat::GradeTooHighException();
}
Bureaucrat::Bureaucrat(const Bureaucrat & copy):_name(copy._name), _grade(copy._grade){}

// copy assignment operator overloading 
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
  if (this != &copy)
    this->_grade = copy._grade;
  // we can't copy name because its const 
  return (*this);
}
// destructor
Bureaucrat::~Bureaucrat(){}


// getters
int Bureaucrat::getGrade() const
{
  return (_grade);
}

const std::string& Bureaucrat::getName() const
{
  return (_name);
}

// member functions
void Bureaucrat::increment()
{
  if (_grade <= 1)
    throw Bureaucrat::GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrement()
{
  if (_grade >= 150)
    throw Bureaucrat::GradeTooLowException();
  _grade++;
}

// excepitions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
};

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
};

// operators ovloading
std::ostream& operator<<(std::ostream & os, const Bureaucrat & obj)
{
  os << obj.getName() << ", bureaucrat grade "<< obj.getGrade() << ".";
  return (os);
}
