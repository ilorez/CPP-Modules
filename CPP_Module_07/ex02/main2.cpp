#include "./includes/Array.hpp"
#include <iostream>


int main()
{
  Array<int> arr(4);
  std::cout << arr[0] << std::endl;
  arr[0] = 66;
  std::cout << arr[0] << std::endl;
  

}

