#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "iostream"

class Animal {
  protected:
    std::string _type;
  public:
    // Orthodox Canonical Form
    Animal();
    virtual ~Animal();
    Animal(Animal &copy);
    Animal& operator=(Animal &copy);

    // Custom Constructors
    Animal(std::string type);
    
    // member functions
    virtual void makeSound() const;

    // getters
    const std::string getType() const;
  
};

#endif
