#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Animal {
protected:
public:
  std::string name;
  std::int16_t age;
  std::string randome = "0000";

  Animal(std::string name, std::int16_t age) : name(name), age(age) {}
  // method
  virtual void printInfo() {
    std::cout << "----------------" << std::endl;
    std::cout << "pet name: " << this->name << std::endl;
    std::cout << "pet age: " << this->age << std::endl;
  }
  // setters
  void setName(std::string name) { this->name = name; }
  void setAge(std::int16_t age) { this->age = age; }
};

class Pets : public Animal {
  std::string owner_name;
  std::string owner_num;

public:
  Pets(std::string name, std::int16_t age, std::string owner_name,
       std::string owner_num)
      : Animal(name, age), owner_num(owner_num), owner_name(owner_name) {
    this->randome = "1111";
  }
  void printInfo() override {
    std::cout << "----------------" << std::endl;
    std::cout << "pet name: " << this->name << std::endl;
    std::cout << "pet age: " << this->age << std::endl;
    std::cout << "owner name: " << this->owner_name << std::endl;
    std::cout << "owner num: " << this->owner_num << std::endl;
  }
};

int main(void) {

  std::vector<Animal*> animals;
  Animal a("ms3od", 2);
  animals.push_back(&a);
  Pets p("hmitouch", 1, "Youssef", "0612345678");
  animals.push_back(&p);
  for (auto *animal:animals)
  {
    animal->printInfo();
    std::cout << animal->randome;
  }

  return (0);
}

// class -- describes the structure
// object -- a specific example of that structure (instance)
// instance -- another name for object
// instantiating -- creating an object from a class
// data members -- variables inside class
// methods -- functions inside class
// construction -- is a special method that is automatically called when an object of a class is created. (Animal(), Pets())

// abstraction -- a concept where you make something easy by hiding the
// complicated stuff
//
// encapsulation -- granting access to private data only through controller public interfaces
// public - members are accessible from outside the class
// private - members cannot be accessed (or viewed) from outside the class
// protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
//
// inheritance -- we can create derived classes that inherit properties from
// their parent classes
//
// polymorphism -- we can treat multiple different objects as their base object
// type

//
