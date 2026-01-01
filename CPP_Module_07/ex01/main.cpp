#include <iostream>
#include "./includes/iter.hpp"

void print(int &a)
{
  std::cout << "Num: " << a << std::endl;
}

void printconst(const char &c)
{
  std::cout << "char: " << c << std::endl;
}

int main( void ) 
{
  int arr1[] = {1, 2, 3};
  const char arr2[] = {'A', 'B', 'C'};

  iter(arr1, 3, print);
  iter(arr2, 3, printconst);
  return 0;
}
