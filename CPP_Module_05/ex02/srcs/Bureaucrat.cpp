
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

// Constructors
Bureaucrat::Bureaucrat():_name("unkown"), _grade(150){}
Bureaucrat::Bureaucrat(std::string name):_name(name), _grade(150){}
Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
{
  _gradeCheck(_grade);
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
  _gradeCheck(_grade - 1);
  _grade--;
}

void Bureaucrat::decrement()
{
  _gradeCheck(_grade + 1);
  _grade++;
}

void Bureaucrat::signForm(AForm& form) const
{
  try 
  {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  } catch (const std::exception& e)
  {
        std::cout << this->_name << " couldn’t sign " 
                  << form.getName() << " because " << e.what() 
                  << "." << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm&  form) const
{
  try 
  {
    form.execute(*this);
    std::cout << this->_name << " executed " << form.getName() << std::endl;
  } catch (const std::exception& e)
  {
        std::cout << this->_name << " couldn’t execute " 
                  << form.getName() << " because " << e.what() 
                  << "." << std::endl;
  }
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

// private out of subject member functions
void Bureaucrat::_gradeCheck(int g) const
{
  if (g > 150)
    throw Bureaucrat::GradeTooLowException();
  if (g < 1)
    throw Bureaucrat::GradeTooHighException();
}

