#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include "iostream"
#include <ostream>

class Form
{
  private:
    const std::string _name;
    bool _is_signed;
    const int _req_grd_2signe;
    const int _req_grd_2exec;
    void _gradeCheck(int) const;
  public:
    // Orthodox Cononical form
    Form();
    ~Form();
    Form(const Form& copy);
    Form& operator=(const Form& copy);

    // custom constructor
    Form(std::string name);
    Form(std::string, bool, int, int);
    Form(std::string, int, int);

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
    class FormALreadySignedException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
    // memeber functions
    void beSigned(const Bureaucrat& obj);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);


#endif // !FORM_HPP
