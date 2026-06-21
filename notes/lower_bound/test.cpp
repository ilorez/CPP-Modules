
/*
#include <iostream>
#include <string>
int main()
{
  const char* str = "hello";
  std::string bb(str);
  std::cout << bb << std::endl;
}
// */
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::lower_bound

int main() {
    // Vector must be sorted
    std::vector<int> data = {10, 20, 30, 30, 40, 50};

    // Case 1: Target exists (finds the FIRST occurrence of 30)
    auto it1 = std::lower_bound(data.begin(), data.end(), 30);
    std::cout << "Element 30 found at index: " << (it1 - data.begin()) << "\n"; // Output: 2

    // Case 2: Target does not exist (finds the first element >= 35, which is 40)
    auto it2 = std::lower_bound(data.begin(), data.end(), 35);
    std::cout << "First element >= 35 is at index: " << (it2 - data.begin()) << "\n"; // Output: 4

    // Case 3: Target is larger than all elements
    auto it3 = std::lower_bound(data.begin(), data.end(), 60);
    if (it3 == data.end()) {
        std::cout << "No element is greater than or equal to 60.\n";
    }

    return 0;
}
