#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "iostream"

class ShrubberyCreationForm: public AForm
{

  private:
    std::string _target;

  public:

    // OCF
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm&copy);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm & copy);
    
    // custom constructor
    ShrubberyCreationForm(std::string target);
    
    // execptions 
    class ShrubberyCreationFormFileNotOpenException : public std::exception 
    {
        public:
            const char* what() const throw();
    };

    void execute(Bureaucrat const & executor) const;

  protected:
    void executeAction() const;

};
#endif // !
