#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "iostream"

#define BRAINSIZE 100

class Brain {
  private:
    std::string _ideas[100];
  public:
    // Orthodox Canonical Form
    Brain();
    virtual ~Brain();
    Brain(Brain &copy);
    Brain& operator=(Brain &copy);

    // getters
    const std::string getIdea(int index) const;

    // setters
    void setIdea(int index, std::string value);
};

#endif
