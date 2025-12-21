#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
  private:
    Brain *_brain;
  public:
    // Orthodox Canonical Form
    Dog();
    ~Dog();
    Dog(const Dog &copy);
    Dog& operator=(const Dog &copy);

    // Custom Constructors
    Dog(std::string type);
    
    // member functions
    void makeSound() const;

    // getter
    Brain* getBrain() const;

};

#endif
