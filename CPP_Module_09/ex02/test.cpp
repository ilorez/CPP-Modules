#include <sstream>
#include <iostream>

int main()
{
    int A;
    //int B;
    std::string res;
    std::stringstream ss("");
    ss >> A;
    //ss >> B;
    std::cout << A << '\n';           // 33
    //std::cout << B << '\n';           // 22
    std::cout << ss.eof() << '\n';    // 1
    std::cout << ss.fail() << '\n';   // 0
    ss >> res;
    std::cout << res << "$"<<  '\n';   // 0
}
