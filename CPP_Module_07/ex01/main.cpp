#include <iostream>
#include "./includes/iter.hpp"

template <typename T>
void print(T &a)
{
  std::cout << "value: " << a << std::endl;
}

int main( void ) 
{
  int arr1[] = {1, 2, 3};
  const char arr2[] = {'A', 'B', 'C'};

  iter(arr1, 3, print<int>);
  iter(arr2, 3, print<const char>);
  return 0;
}
