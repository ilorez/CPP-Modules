
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"

int main()
{
  const Animal* meta = new Animal();
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  std::cout << "-------------- Dog -----------" << std::endl;
  std::cout << j->getType()  << std::endl;
  j->makeSound();
  std::cout << "-------------- Cat -----------" << std::endl;
  std::cout << i->getType() << std::endl;
  i->makeSound(); //will output the cat sound!
  std::cout << "-------------- Animal -----------" << std::endl;
  meta->makeSound();
  //...
  return 0;
}
