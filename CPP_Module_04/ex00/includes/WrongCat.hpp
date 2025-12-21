#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
  public:
    // Orthodox Canonical Form
    WrongCat();
    ~WrongCat();
    WrongCat(WrongCat &copy);
    WrongCat& operator=(WrongCat &copy);

    // Custom Constructors
    WrongCat(std::string type);
    
    // member functions
    void makeSound() const;
};

#endif
