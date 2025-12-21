
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"
//*
int main()
{
    std::cout << "========== EX01 MAIN TEST ==========\n" << std::endl;

    // ----------------------------------------------------------------
    // 1) Subject requirement:
    //    Create array of Animals (half Dogs, half Cats)
    // ----------------------------------------------------------------
    const int SIZE = 10;
    Animal* animals[SIZE];

    std::cout << "Creating animals...\n" << std::endl;

    for (int i = 0; i < SIZE / 2; i++)
        animals[i] = new Dog();

    for (int i = SIZE / 2; i < SIZE; i++)
        animals[i] = new Cat();

    // ----------------------------------------------------------------
    // 2) Polymorphism check (makeSound)
    // ----------------------------------------------------------------
    std::cout << "\nMaking sounds...\n" << std::endl;

    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();

    // ----------------------------------------------------------------
    // 3) Brain deep-copy test using Cat
    // ----------------------------------------------------------------
    std::cout << "\n========== BRAIN DEEP COPY TEST ==========\n" << std::endl;

    Cat original;
    original.getBrain()->setIdea(0, "Sleep all day");

    std::cout << "-----------" << std::endl;
    Cat copy(original); // copy constructor

    std::cout << "-----Print Idea------" << std::endl;
    copy.getBrain()->setIdea(0, "Climb the wall");

    std::cout << "Original Cat idea[0]: "
              << original.getBrain()->getIdea(0) << std::endl;

    std::cout << "Copied Cat idea[0]:   "
              << copy.getBrain()->getIdea(0) << std::endl;

    // ----------------------------------------------------------------
    // 4) Polymorphic deletion (VERY IMPORTANT)
    // ----------------------------------------------------------------
    std::cout << "\nDeleting animals...\n" << std::endl;

    for (int i = 0; i < SIZE; i++)
        delete animals[i];

    std::cout << "\n========== END OF TEST ==========" << std::endl;

    return 0;
}
// */
