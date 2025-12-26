#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "iostream"

class RobotomyRequestForm: public AForm
{

  private:
    std::string _target;

  public:

    // OCF
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm&copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm & copy);
    
    // custom constructor
    RobotomyRequestForm(std::string target);
    
    // member functions
    void execute(Bureaucrat const & executor) const;
  protected:
    void executeAction() const;

};
#endif // !
