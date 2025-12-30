
#include "../includes/container.h"

Base *_genA()
{
  return new A();
}

Base *_genB()
{
  return new B();
}

Base *_genC()
{
  return new C();
}

Base *generate(void)
{
  Base* (*arr[3])() = {_genA,_genB,_genC};
  return (arr[rand() % 3]());
}

void identify(Base* p)
{
  std::cout << "type: " << std::endl;
}

void identify(Base& p)
{

}
