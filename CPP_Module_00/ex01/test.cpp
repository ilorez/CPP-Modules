#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string line;

    std::cout << "Enter something: ";
    std::getline(std::cin, line);

    std::cout << "You entered: [" << line << "]\n";

    if (line == "HELLO") {
        std::cout << "Match!\n";
    } else {
        std::cout << "No match!\n";
    }

    return 0;
}
