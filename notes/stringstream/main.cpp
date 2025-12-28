
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

int main() {
    std::string literal = "1e400"; // too big for double
    double d;
    std::stringstream ss(literal);
    ss >> d;

    if (std::isinf(d))
        std::cout << "double overflow: " << (d > 0 ? "+inf" : "-inf") << "\n";
    else
        std::cout << std::fixed << std::setprecision(1) << d << "\n";

    float f = static_cast<float>(d);
    if (std::isinf(f))
        std::cout << "float overflow: " << (f > 0 ? "+inff" : "-inff") << "\n";
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";

    return 0;
}

