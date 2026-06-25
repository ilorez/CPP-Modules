#include "includes/PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <exception>
#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include <vector>



int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: require positive integer sequence as an argumen!"
              << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    struct timeval start, end;
    std::vector<int> vec;

	// Vector
    validateInput(vec, argv);
    std::cout << "Before: ";
    printRange(vec.begin(), vec.end());
    gettimeofday(&start, NULL);
	fJSortVec(vec);
    gettimeofday(&end, NULL);
    std::cout << "After: ";
    printRange(vec.begin(), vec.end());
	displayInterval("vector", vec.size(), start, end);



	// Deque
    std::deque<int> deq;
    validateInput(deq, argv);
    std::cout << "Before: ";
    printRange(deq.begin(), deq.end());
    gettimeofday(&start, NULL);
	fJSortVec(vec);
    gettimeofday(&end, NULL);
	std::cout << "After: ";
    printRange(vec.begin(), vec.end());
	displayInterval("deque", vec.size(), start, end);


	

    // DEBUG
    // std::vector<int> order = pendIsertOrder(vec[0]);
    // printRange(order.begin(), order.end());

  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
