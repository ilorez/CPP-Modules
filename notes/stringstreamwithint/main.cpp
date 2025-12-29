
#include <iostream>
#include <sstream>
#include <climits>

int main()
{
    int i = -1;

    // 1️⃣ Normal value
    {
        std::stringstream ss("42");
        ss >> i;
        std::cout << "Normal: i = " << i
                  << ", fail = " << ss.fail() << "\n";
    }

    // 2️⃣ Too large for int (overflow)
    {
        i = -1;
        std::stringstream ss("999999999999999999");
        ss >> i;
        std::cout << "Overflow: i = " << i
                  << ", fail = " << ss.fail() << "\n";
    }

    // 3️⃣ Too small for int (underflow)
    {
        i = -1;
        std::stringstream ss("-999999999999999999");
        ss >> i;
        std::cout << "Underflow: i = " << i
                  << ", fail = " << ss.fail() << "\n";
    }

    // 4️⃣ Mixed characters
    {
        i = -1;
        std::stringstream ss("42abc");
        ss >> i;
        std::cout << "Partial parse: i = " << i
                  << ", fail = " << ss.fail() << "\n";
    }

    // 5️⃣ Not a number
    {
        i = -1;
        std::stringstream ss("abc");
        ss >> i;
        std::cout << "Invalid: i = " << i
                  << ", fail = " << ss.fail() << "\n";
    }

    // 6️⃣ Ensure full parsing
    {
        i = -1;
        std::stringstream ss("999abc");
        char c;
        if (!(ss >> i))
            std::cout << "Full check: INVALID 1\n" << i;
        else if ((ss >> c))
            std::cout << "Full check: INVALID 2\n" << c;
        else
            std::cout << "Full check: VALID, i = " << i << "\n";
    }

    return 0;
}
