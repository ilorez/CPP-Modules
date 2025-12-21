#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include "iostream"

class WrongAnimal {
  protected:
    std::string _type;
  public:
    // Orthodox Canonical Form
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(WrongAnimal &copy);
    WrongAnimal& operator=(WrongAnimal &copy);

    // Custom Constructors
    WrongAnimal(std::string type);
    
    // member functions
    void makeSound() const;

    // getters
    const std::string getType() const;
  
};

#endif
