#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal {
  public:
    // Orthodox Canonical Form
    Cat();
    ~Cat();
    Cat(Cat &copy);
    Cat& operator=(Cat &copy);

    // Custom Constructors
    Cat(std::string type);
    
    // member functions
    void makeSound() const;
};

#endif
