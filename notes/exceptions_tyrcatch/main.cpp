//#include <exception>
//#include <iostream>
//#include <stdexcept>
//int main()
//{
//  int b = 0;
//  try {
//    if (b==0)
//      throw std::runtime_error("devide by 0");
//    int a = 5/b;
//    (void)a;
//  }
//  catch (const std::exception &e) 
//  {
//    std::cout << "error: " << e.what() << std::endl;
//  }
//}

#include <iostream>
#include <new>

int main()
{
    try {
        // Try to allocate a huge amount of memory
        int* p = new int[1000000000000ULL];
        (void)p;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Allocation failed: " << e.what() << std::endl;
    }
}
