#include "./includes/Container.hpp"
/*
int main()
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
  return 0;
}
// */
/*
int main()
{
    // Create characters
    Character alice("Alice");
    Character bob("Bob");

    // Create Materia
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    // Equip Materia to Alice
    alice.equip(ice);
    alice.equip(cure);

    std::cout << "--- Using Materia from Alice ---" << std::endl;
    // Use each Materia
    alice.use(0, bob); // Ice on Bob
    alice.use(1, bob); // Cure on Bob

    std::cout << "--- Cloning Materia ---" << std::endl;
    AMateria* iceClone = ice->clone();
    std::cout << "Cloned Materia type: " << iceClone->getType() << std::endl;

    // Equip cloned Materia to Bob
    bob.equip(iceClone);
    bob.use(0, alice);

    // Clean up
    // Character destructors should delete equipped Materias
    return 0;
}
// */
int main()
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);


  me->unequip(0);

  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
  return 0;
}
