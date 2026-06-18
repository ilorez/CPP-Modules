#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
  private:
    int _N;
    std::vector<int> _arr;
  public:
    // orthx
    Span(int N);
    Span();
    ~Span();
    Span(const Span& copy);
    Span& operator=(const Span& copy);

    void addNumber(int num);
    class FullExeption: public std::exception {
      public:
        const char* what() const throw();
    };

    int shortestSpan();
    int longestSpan();

    class EmptyExeption: public std::exception {
      public:
        const char* what() const throw();
    };

    void fillRange(std::iterator);
};

#endif
