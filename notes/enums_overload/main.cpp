#include <iostream>

enum Traffic_light { green, yellow, red };

// Prefix increment for Traffic_light
Traffic_light& operator++(Traffic_light& t)
{
    switch (t)
    {
        case green:  t = yellow; break;
        case yellow: t = red;    break;
        case red:    t = green;  break;
    }
    return t; // return the updated traffic light by reference
}

// Helper function to print traffic light
const char* to_string(Traffic_light t)
{
    switch (t)
    {
        case green:  return "green";
        case yellow: return "yellow";
        case red:    return "red";
    }
    return "unknown";
}

int main()
{
    Traffic_light light = green;

    std::cout << "Initial light: " << to_string(light) << std::endl;

    Traffic_light next = ++light; // Prefix increment
    std::cout << "After ++light, light: " << to_string(light)
              << ", next: " << to_string(next) << std::endl;

    ++light; // another increment
    std::cout << "After another ++light, light: " << to_string(light) << std::endl;

    return 0;
}

