#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "iostream"

class PresidentialPardonForm: public AForm
{

  private:
    std::string _target;

  public:

    // OCF
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm&copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm & copy);
    
    // custom constructor
    PresidentialPardonForm(std::string target);
    
    // member functions
    void execute(Bureaucrat const & executor) const;
  protected:
    void executeAction() const;

};
#endif // !
