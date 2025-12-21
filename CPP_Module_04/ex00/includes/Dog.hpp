#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog: public Animal {
  public:
    // Orthodox Canonical Form
    Dog();
    ~Dog();
    Dog(Dog &copy);
    Dog& operator=(Dog &copy);

    // Custom Constructors
    Dog(std::string type);
    
    // member functions
    void makeSound() const;
};

#endif
