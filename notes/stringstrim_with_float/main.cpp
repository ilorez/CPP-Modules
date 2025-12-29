
#include <iostream>
#include <sstream>
#include <cmath>    // std::isinf, std::isnan
#include <iomanip>  // optional, for nicer formatting

int main()
{
    // Positive infinity test
    std::stringstream ss("99999999999999999999999999999999999");
    float pos_inf;
    if (!(ss >> pos_inf))
    {
      std::cout << "invalid" << std::endl;
      return 0;
    }

    char sign = (pos_inf > 0) ? '+' : '-';

    std::cout << "+inf: "
              << "sign = " << sign
              << ", isinf = " << std::boolalpha << std::isinf(pos_inf)
              << ", isnan = " << std::isnan(pos_inf)
              << ", number = " << pos_inf << "\n";

    return 0;
}

