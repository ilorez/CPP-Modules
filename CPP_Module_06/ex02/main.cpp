#include "./includes/container.h"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

//class D: public Base{};

int main()
{
    std::srand(std::time(NULL));
    //D *a = new D();

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Test " << i + 1 << ": ";

        Base* obj = generate();

        std::cout << "identify(Base*): ";
        identify(obj);

        std::cout << "identify(Base&): ";
        identify(*obj);

        delete obj;
        std::cout << "-------------------" << std::endl;
    }

    return 0;
}

