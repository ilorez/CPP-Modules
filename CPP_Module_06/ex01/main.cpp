#include <iostream>
#include "./includes/Data.hpp"
#include "./includes/Serializer.hpp"

int main() {
    Data data;

    data.setName("ilorez");
    data.setValue(8);

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);

    // Deserialize
    Data* ptr = Serializer::deserialize(raw);

    // Tests
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Deserialized address: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "SUCCESS: addresses match" << std::endl;
    else
        std::cout << "FAIL: addresses do not match" << std::endl;

    std::cout << "name = " << ptr->getName() << std::endl;
    std::cout << "value = " << ptr->getValue() << std::endl;

    return 0;
}
