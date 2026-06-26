#include "includes/PmergeMe.hpp"
#include <cstdlib>
#include <deque>
#include <exception>
#include <iostream>
#include <vector>


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cerr << "Error: require positive integer sequence as an argumen!" << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    PmergeMe<std::vector> vec;
	vec.sort(argv);

    PmergeMe<std::deque> deq;
	deq.sort(argv);

	// Display Info
	vec.displayInput();
	vec.displayMainChain();
	vec.displayInterval("std::vector");
	deq.displayInterval("std::deque");

	// DEBUG
    //re.printAll();
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
