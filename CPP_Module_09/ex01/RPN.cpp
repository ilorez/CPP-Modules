#include "./includes/RPN.hpp"
#include <cctype>
#include <iostream>
#include <stdexcept>

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& copy){*this=copy;}
RPN& RPN::operator=(const RPN& copy){
  if (this == &copy)
    return *this;
  return *this;
}

// this method ignore spaces
// this valid "1      1      +" => 2
int RPN::calcule(const char* exp) {

  int re;
  for (int i = 0; exp[i]; i++)
  {
    if (std::isspace(exp[i]))
        continue;
    //std::cout << "char: " << exp[i] << std::endl;
    if (exp[i] > 47 && exp[i] < 58)
    {
      _container.push(exp[i] - 48);
      if (!std::isspace(exp[i+1]))
        throw RPNException("accept one digit as number (0-9)");
      continue;
    }
    if (_container.size() < 2)
      throw RPNException("invalid exp");
    int a = _container.top();
    _container.pop();
    int b = _container.top();
    _container.pop();
    switch (exp[i]) {
      case '/':
        if (a == 0)
          throw RPNException("math error can't devide by 0");
        re = b / a;
        break;
      case '*':
        re = b * a;
        break;
      case '+':
        re = b + a;
        break;
      case '-':
        re = b - a;
        break;
      default:
        throw RPNException("operator not found"); break;
    }
    _container.push(re);
  }
  if (_container.size() == 0)
    throw RPNException("empty exp");
  if (_container.size() != 1)
    throw RPNException("stack have more then one number at end of calculation");
  re = _container.top();
  _container.pop();
  return re;
}

// exception
RPN::RPNException::RPNException(std::string msg): _msg(msg){}
RPN::RPNException::~RPNException() throw(){}
const char* RPN::RPNException::what() const throw() {return _msg.c_str();}
