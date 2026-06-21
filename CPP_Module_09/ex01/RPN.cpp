#include "./includes/RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& copy){*this=copy;}
RPN& RPN::operator=(const RPN& copy){return *this;}

int RPN::calcule(const char* exp) {

  for (int i; exp[i]; i++)
  {
    if (exp[i] > 47 && exp[i] < 58)
      _container.push(exp[i] - 48);
    if (_container.size() < 2)
      throw "error";
    int a = _container.top();
    _container.pop();
    int b = _container.top();
    _container.pop();
    int re;
    switch (exp[i]) {
      case '/':
        re = a/b;
        break;
      case '*':
        re = a*b;
        break;
      case '+':
        re = a+b;
        break;
      case '-':
        re = a-b;
        break;
      default:
        throw "operator not found"; break;
    }
    _container.push(re);
  }
  if (_container.size() != 1)
    throw "error";

}
