#include <iostream>
int main()
{
  const int a = 10;
  const int *p1 = &a;
  int *p2 = const_cast<int*>(p1);
  *p2 = 20;
  *p2+=1;
  std::cout << &a << std::endl;
  std::cout << p2 << std::endl;
  std::cout << a << std::endl;
  std::cout << *p2 << std::endl;

}
// becuase of compiler replace a with 10 like what happen with macros

