#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stack>
class RPN {
  private:
    std::stack<int> _container;
  public:
    RPN();
    ~RPN();
    RPN(const RPN& copy);
    RPN& operator=(const RPN& copy);

    void calcule(const char*str);
};
#endif
