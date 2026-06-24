#include "includes/PmergeMe.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>


int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error: require positive integer sequence as an argumen!" << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    PmergeMe re;
    re.validateInput(argv[1]);
    re.createPairList();
    re.sortPairs();
    re.setupChains();
    re.generateJacobsthalSq();
    re.insertPends();
	re.displayInfo();
    
	// DEBUG
    //re.printAll();
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
