#include "includes/Span.hpp"

Span::Span():_N(0){};
Span::Span(int n):_N(n){};
Span::Span(const Span& copy){
  *this = copy;
};
Span::~Span(){}

// operator =
Span& Span::operator=(const Span& copy) {
  if (this != &copy)
  {
    this->_N = copy._N;
    for (int i = 0; i < _N; i++)
      _arr[i] = copy._arr[i];
  }
  return *this;
}

