#include "includes/PmergeMe.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <deque>
#include <exception>
#include <iostream>
#include <sys/select.h>
#include <vector>


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cerr << "Error: require positive integer sequence as an argumen!" << std::endl;
    return (EXIT_FAILURE);
  }
  try {
	  struct timeval start, end;
	  std::vector<int> vec;
	  std::deque<int> deq;

	  validateInput(vec, argv);
	  validateInput(deq, argv);

	  std::cout <<  "Before: ";
	  printRange(vec.begin(), vec.end());

	  gettimeofday(&start, NULL);
	  // run algo on vec
	  gettimeofday(&end, NULL);
	  // print after

	  std::cout <<  "Before: ";
	  printRange(deq.begin(), deq.end());
	  gettimeofday(&start, NULL);
	  // run algo on deq
	  gettimeofday(&end, NULL);
	  // print after


	  // print elapsed time interval
	
	  // DEBUG
	  //std::vector<int> order = pendIsertOrder(vec[0]); 
	  //printRange(order.begin(), order.end());
	
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
