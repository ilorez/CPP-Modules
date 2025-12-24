#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "iostream"

class Character{
  private:
    std::string _name;
  public:
    // Orthodox Canonical Form
    Character();
    ~Character();
    Character(const Character &copy);
    Character& operator=(const Character &copy);

    // custom consructor
    Character(std::string const &name);
    

    // member functions
    std::string const & getName() const;
};

#endif
