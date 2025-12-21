#include <iostream>
/*
class A {
public:
    int value;
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    D d;

    // ❌ Ambiguous: two A subobjects
    //d.value = 42;

    // You must specify which A
    d.B::value = 10;
    d.C::value = 20;

    std::cout << "B::A value = " << d.B::value << std::endl;
    std::cout << "C::A value = " << d.C::value << std::endl;

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

class B : public A {
public:
    B() {
        std::cout << "B constructor called" << std::endl;
    }
};

class C : public A {
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
    std::cout << "Creating D (without virtual):" << std::endl;
    D d;
    return 0;
}

