
#include <iostream>
#include <cstdint>

struct Data {
    int x;
    char c;
};

int main() {
    Data data;
    data.x = 42;
    data.c = 'A';

    // Serialize: pointer -> uintptr_t
    uintptr_t raw = reinterpret_cast<uintptr_t>(&data);

    // Deserialize: uintptr_t -> pointer
    Data* ptr = reinterpret_cast<Data*>(raw);

    // Test
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Deserialized address: " << ptr << std::endl;

    std::cout << "x = " << ptr->x << std::endl;
    std::cout << "c = " << ptr->c << std::endl;
    int *p = reinterpret_cast<int *>(ptr);
    std::cout << "x cast: " << *p << std::endl;
    p++;
    char *c = reinterpret_cast<char *>(p);
    std::cout << "c cast: " << *c << std::endl;

    return 0;
}
