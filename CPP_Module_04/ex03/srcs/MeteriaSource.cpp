
#include "../includes/Container.hpp"
#include "../includes/Debug.hpp"

// constructors
MateriaSource::MateriaSource(){
  for (int i=0; i < MSLOTS; i++)
    _knowledge_book[i] = NULL;
};
MateriaSource::MateriaSource(MateriaSource const &copy) { *this = copy; };

// assignment operator overloading 
MateriaSource& MateriaSource::operator=(MateriaSource const &copy)
{
  if (&copy != this)
  {
    for (int i=0; i < MSLOTS; i++)
    {
      if (this->_knowledge_book[i])
          delete this->_knowledge_book[i];
      if (copy._knowledge_book[i])
        _knowledge_book[i] = copy._knowledge_book[i]->clone();
      else
        _knowledge_book[i] = NULL;
    }
  }
  return (*this);
}
// destructor
MateriaSource::~MateriaSource()
{
  for (int i=0; i < MSLOTS; i++)
    if (_knowledge_book[i])
      delete _knowledge_book[i];
};


// member functions
void MateriaSource::learnMateria(AMateria* m)
{
  if (!m)
  {
    DEBUG_ERROR("MateriaSource::learnMateria null pointer");
    return;
  }
  for (int i=0; i < MSLOTS; i++)
  {
    if (!_knowledge_book[i])
    {
      _knowledge_book[i] = m->clone(); 
      // MateriaSource owns the clone
      // caller still owns the original
      // if caller leaks means caller’s fault
      DEBUG_INFO("MateriaSource learned materia type=" << m->getType());
      return ;
    }
  }
    DEBUG_WARN("MateriaSource storage full, cannot learn " << m->getType());
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
  for (int i=0; i < MSLOTS; i++)
  {
    if (_knowledge_book[i] && _knowledge_book[i]->getType() == type)
    {
      DEBUG_INFO("MateriaSource created materia type=" << type);
      return (_knowledge_book[i]->clone());
    }
  }
  DEBUG_WARN("MateriaSource unknown materia type=" << type);
  return (0);
}

