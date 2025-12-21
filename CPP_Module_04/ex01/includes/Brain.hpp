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
    ~Brain();
    Brain(const Brain &copy);
    Brain& operator=(const Brain &copy);

    // getters
    const std::string getIdea(int index) const;

    // setters
    void setIdea(int index, std::string value);
};

#endif
