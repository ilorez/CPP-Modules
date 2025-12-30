
#include "../includes/container.h"

#define DN 3
Base *_genA()
{
  std::cout << "Generate: A  "<< std::endl ;
  return new A();
}

Base *_genB()
{
  std::cout << "Generate: B  " << std::endl ;
  return new B();
}

Base *_genC()
{
  std::cout << "Generate: C  "<< std::endl ;
  return new C();
}

Base *generate(void)
{
  Base* (*arr[DN])() = {_genA,_genB,_genC};
  return (arr[rand() % DN]());
}

void identify(Base* p)
{
  std::string type = "unknown";
  if (dynamic_cast<A*>(p))
    type = "A";
  else if (dynamic_cast<B*>(p))
    type = "B";
  else if (dynamic_cast<C*>(p))
    type = "C";
  std::cout << "type: " << type << std::endl;
}

void identify(Base& p)
{
  std::cout << "type: ";
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    return ;
  } catch (std::exception &e){}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    return ;
  } catch (std::exception &e){}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    return ;
  } catch (std::exception &e){}
  std::cout << "unknown" << std::endl;
}
