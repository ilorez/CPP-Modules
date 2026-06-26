#include "includes/PmergeMe.hpp"
#include <sys/time.h>



int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: require positive integer sequence as an argumen!"
              << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    struct timeval start, end;

	// Vector
    std::vector<int> vec;
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
	fJSortDeq(deq);
    gettimeofday(&end, NULL);
	std::cout << "After: ";
    printRange(deq.begin(), deq.end());
	displayInterval("deque", deq.size(), start, end);


    // DEBUG
    // std::vector<int> order = pendIsertOrder(vec[0]);
    // printRange(order.begin(), order.end());

  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
