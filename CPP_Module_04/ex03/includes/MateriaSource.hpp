#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define MSLOTS 4

class MateriaSource: public IMateriaSource {
  private:
    AMateria* _knowledge_book[MSLOTS];

  public:
    // Orthodox Canonical Form
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &copy);
    MateriaSource& operator=(const MateriaSource &copy);

    // member functions
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
