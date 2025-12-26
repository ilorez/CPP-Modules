#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "iostream"

class Intern
{
  public:
    // OCF
    Intern();
    ~Intern();
    Intern(const Intern &copy);
    Intern& operator=(const Intern  & copy);
  
    // member functions
    AForm* makeForm(std::string form, std::string target) const;
    /* exeptions
    class FormNotFoundException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
    */
};
#endif // !INTERN_HPP
