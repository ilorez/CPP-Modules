#include "includes/BitcoinExchange.hpp"
#include <algorithm>
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  try {
    BitcoinExchange b;
    b.readDb();
    b.readInput(argv[1]);
  } catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }



  return 0;
}
