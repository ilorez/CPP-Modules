#include <iostream>
#include <iomanip>

int main()
{
    double x = 1234333.456;
    double y = 42;

    std::cout << "=== setprecision alone ===\n";
    //std::cout << std::setprecision(3) << x << "\n";   // 123
    //std::cout << std::setprecision(1) << y << "\n";   // 4e+01

    std::cout << "\n=== fixed alone ===\n";
    //std::cout << std::fixed << x << "\n";             // 123.456000

    std::cout << "\n=== fixed + setprecision ===\n";
    std::cout << std::setprecision(4) << x << "\n";   // 123.46
    std::cout << std::setprecision(1) << y << "\n";   // 42.0

    // Reset formatting
    std::cout << std::defaultfloat;

    std::cout << "\n=== after reset ===\n";
    std::cout << y << "\n";                           // 42

    return 0;
}
