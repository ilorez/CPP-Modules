/*
#include <iostream>

class Base {
public:
    virtual ~Base() {} // must be polymorphic
};

class Derived : public Base {
public:
    void sayHello() { std::cout << "Hello from Derived!\n"; }
};

int main() {
    Base *b = new Derived;
    Base *b2 = new Base;

    // dynamic_cast to Derived*
    if (Derived *d = dynamic_cast<Derived*>(b)) {
        d->sayHello(); // works
    } else {
        std::cout << "Cast failed\n";
    }

    if (Derived *d2 = dynamic_cast<Derived*>(b2)) {
        d2->sayHello();
    } else {
        std::cout << "Cast failed\n"; // will print
    }

    delete b;
    delete b2;
    return 0;
}
// */
//*
#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

int main() {
    Derived b; // NOT a Derived object

    std::cout << &b << std::endl;
    try {
        Base& ref = b;
        Derived& d = dynamic_cast<Derived&>(ref); // throws
        std::cout << &d << std::endl;
        (void)d;
    } catch (const std::bad_cast& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
