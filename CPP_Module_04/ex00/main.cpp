
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"
#include "./includes/WrongCat.hpp"

int main()
{
  //*
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
    delete meta;
    delete j;
    delete i;
    return 0;
  }
  // */
  /*
  {
    std::cout << "=== Creating WrongAnimal ===\n";
    WrongAnimal animal;
    animal.makeSound();

    std::cout << "\n=== Creating WrongCat ===\n";
    WrongCat cat;
    cat.makeSound();

    std::cout << "\n=== Using WrongAnimal pointer to WrongCat ===\n";
    WrongAnimal* ptr = new WrongCat();
    std::cout << "Type: " << ptr->getType() << "\n";
    ptr->makeSound(); // ❌ calls WrongAnimal::makeSound

    std::cout << "=== ----- ===" << std::endl;
    delete ptr;
    std::cout << "=== ----- ===" << std::endl;

    return 0;
  }
  // */
}


/*
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
...
return 0;
}
*/
