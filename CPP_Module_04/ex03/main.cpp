#include "./includes/Container.hpp"

// ---- AI test
/*
int main() { // Create characters
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

// -------- My tests
//*
int main()
{
  IMateriaSource* src = new MateriaSource();
  std::cout  << "1 ---" << std::endl;
  Ice ice;
  Cure cure;
  src->learnMateria(&ice);
  std::cout  << "2 ---" << std::endl;
  src->learnMateria(&cure);
  std::cout  << "3 ---" << std::endl;

  ICharacter* me = new Character("MyCharacter");

  AMateria* tmp;
  for (int i = 0; i < CSLOTS + 1 ; i++)
  {
    if (i%2)
      tmp = src->createMateria("ice");
    else
      tmp = src->createMateria("cure");
    me->equip(tmp);
  }
  // because the last tmp will found slots used
  delete tmp;
  me->unequip(0);
  me->unequip(1);
  me->unequip(2);
  ICharacter* bob = new Character("bob");
  me->use(1, *bob);
  me->use(3, *bob);

  delete bob;
  delete me;
  delete src;
  clearFloor();
  return 0;
}
// */

// ---- Subject test
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

// ---- Fixed Subject test
/*
int main()
{
  IMateriaSource* src = new MateriaSource();
  Ice ice;
  Cure cure;
  src->learnMateria(&ice);
  src->learnMateria(&cure);
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
