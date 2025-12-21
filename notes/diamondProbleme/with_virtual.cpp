/*
 
#include <iostream>

class A {
public:
    int value;
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D d;

    // ✅ No ambiguity: only one A
    d.value = 42;

    std::cout << "Value = " << d.value << std::endl;

    return 0;
}
*/

#include <iostream>

class A {
public:
    A() {
        std::cout << "A constructor called" << std::endl;
    }
};

class B : virtual public A {
public:
    B() {
        std::cout << "B constructor called" << std::endl;
    }
};

class C : virtual public A {
public:
    C() {
        std::cout << "C constructor called" << std::endl;
    }
};

class D : public B, public C {
public:
    D() {
        std::cout << "D constructor called" << std::endl;
    }
};

int main() {
    std::cout << "Creating D (with virtual):" << std::endl;
    D d;
    return 0;
}

