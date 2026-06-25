#ifndef PMERGEME_HPP
#define PMERGEME_HPP

// member functions

#include <set>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>

// functions
std::vector<int> pendIsertOrder(size_t size);

template <typename C>
void validateInput(C &input, char **sequence) {
  int tmp_var;
  std::set<int> tmp_for_dup;

  for (int i = 1; sequence[i]; i++) {
    std::stringstream ss(sequence[i]);
    ss >> tmp_var;
    if (ss.fail() || !ss.eof())
      throw std::runtime_error("argumnet should be positive integer sequence.");
    if (tmp_var <= 0)
      throw(std::runtime_error("all number must be positive."));
	if (!tmp_for_dup.insert(tmp_var).second)
      throw(std::runtime_error("caught duplicated number"));
    input.push_back(tmp_var);
  }
};


template<typename Iterator>
void printRange(Iterator start, Iterator end)
{
	while (start != end)
		std::cout << *start++ << " ";
	std::cout << std::endl;
}

#endif
