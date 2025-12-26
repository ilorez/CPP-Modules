#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include "iostream"
#include <ostream>

class AForm
{
  private:
    const std::string _name;
    bool _is_signed;
    const int _req_grd_2signe;
    const int _req_grd_2exec;
    void _gradeCheck(int) const;
  public:
    // Orthodox Cononical form
    AForm();
    virtual ~AForm();
    AForm(const AForm& copy);
    AForm& operator=(const AForm& copy);

    // custom constructor
    AForm(std::string name);
    AForm(std::string, bool, int, int);
    AForm(std::string, int, int);

    // getters
    const std::string& getName() const;
    bool isSigned() const; 
    int getRequiredGrade2Signe() const; 
    int getRequiredGrade2Exec() const; 


    // exeptions
    class GradeTooHighException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
    class AFormAlreadySignedException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
    class AFormNotSignedException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
    // memeber functions
    void beSigned(const Bureaucrat& obj);
    virtual void execute(Bureaucrat const & executor) const = 0;
  protected:
    virtual void executeAction() const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);


#endif // !AFORM_HPP
