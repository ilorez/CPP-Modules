#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stack>
#include <string>
class RPN {
  private:
    std::stack<int> _container;
  public:
    RPN();
    ~RPN();
    RPN(const RPN& copy);
    RPN& operator=(const RPN& copy);
    int calcule(const char*str);
    class RPNException: public std::exception {
      private:
        std::string _msg;
      public:
        RPNException(std::string msg);
        ~RPNException();
        const char * what() const throw();
    };
};
#endif
