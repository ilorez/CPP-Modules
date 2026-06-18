#include "includes/Span.hpp"
#include <algorithm>
#include <iterator>

Span::Span():_N(0){};
Span::Span(unsigned long n):_N(n){};
Span::Span(const Span& copy){
  *this = copy;
};
Span::~Span(){}

// operator =
Span& Span::operator=(const Span& copy) {
  if (this != &copy)
  {
    this->_N = copy._N;
    for (unsigned long i = 0; i < _N; i++)
      _arr[i] = copy._arr[i];
  }
  return *this;
}

void Span::addNumber(int num)
{
  if (_arr.size() == _N)
    throw Span::FullExeption();
  _arr.push_back(num);
}

int Span::shortestSpan()
{
  // check that there is 2 element at least
  if (_arr.size() < 2)
   throw EmptyExeption();
  std::sort(_arr.begin(), _arr.end());
  int short_span;
  int tmp;
  short_span = std::abs(_arr[1] - _arr[0]);
  for (unsigned long i = 1; i < _N - 1; i++)
  {
    tmp = _arr[i+1] - _arr[i];
    tmp = std::abs(tmp);
    if (tmp < short_span)
      short_span = tmp;
  }
  return short_span;
}

int Span::longestSpan()
{
  if (_arr.size() < 2)
   throw EmptyExeption();
  int max = *(std::max_element(_arr.begin(), _arr.end())).base();
  int min = *(std::min_element(_arr.begin(), _arr.end())).base();
  return std::abs(max - min);
}

// Exceptions
const char* Span::EmptyExeption::what()  const throw() {

  return "no span can be found";
}

const char* Span::FullExeption::what()  const throw() {

  return "Span filled";
}



void Span::fillRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
  std::vector<int>::iterator it = _arr.begin();
  while (start != end)
  {
    *it = *start;
    it++; start++;
  }
}

