
#include "../includes/MateriaSource.hpp"


// constructors
MateriaSource::MateriaSource(){};
MateriaSource::MateriaSource(MateriaSource const &copy){
  *this = copy;
};
// assignment operator overloading 
MateriaSource& MateriaSource::operator=(MateriaSource const &copy)
{
  if (&copy != this)
  {
    // TODO:deep copy
  }
  return (*this);
}
// destructor
MateriaSource::~MateriaSource(){};


// member functions
void MateriaSource::learnMateria(AMateria* m)
{
  if (!m)
  {
    std::cout << "learnMateria: matria is invalid" << std::endl;
    return;
  }
  for (int i=0; i < MSLOTS; i++)
  {
    if (!_knowledge_book[i])
    {
      _knowledge_book[i] = m->clone();
      std::cout << "learnMateria: new matria of type " << m->getType() << " has been learned" << std::endl;
      return ;
    }
  }
  std::cout << "learnMateria: materia couldn't learned because no slots left" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
  for (int i=0; i < MSLOTS; i++)
  {
    if (_knowledge_book[i] && _knowledge_book[i]->getType() == type)
      return (_knowledge_book[i]->clone());
  }
  std::cout << "createMateria: materia type is unknown" << std::endl;
  return (0);
}

