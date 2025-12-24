#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include <ostream>

class Bureaucrat
{
  private:
    const std::string _name;
    int _grade;
  public:

    // Orthodox Cononical form
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);

    // custom constructor
    Bureaucrat(std::string name, int grade);
    Bureaucrat(std::string name);

    // getters
    const std::string& getName() const;
    int getGrade() const; 

    // member functions
    void increment();
    void decrement();

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
    
};

std::ostream& operator<<(std::ostream& st, const Bureaucrat& obj);

#endif // !BUREAUCRAT_HPP
