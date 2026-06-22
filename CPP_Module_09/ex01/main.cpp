#include "includes/RPN.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Error: require exp as argument" << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    RPN ex;
    int re = ex.calcule(argv[1]);
    std::cout << re <<  std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
