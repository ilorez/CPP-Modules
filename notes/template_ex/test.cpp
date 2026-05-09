#include <iostream>

int main()
{
  int *a = new int();
  std::cout << a << std::endl;
  std::cout << *a << std::endl;
  delete a;
}

