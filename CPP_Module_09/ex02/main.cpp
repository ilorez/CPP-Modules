#include "includes/PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <exception>
#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include <vector>

void fJSort(std::vector<int> &vec) {
  // base stop rec
  if (vec.size() == 1) {
    return;
  }

  std::vector<std::pair<int, int> > pairs;
  int straggler = 0;
  if (vec.size() % 2) {
    straggler = vec.back();
    vec.pop_back();
  }

  // create pair list
  for (size_t i = 0; i < vec.size(); i += 2) {
    // sort pair
    if (vec[i] > vec[i + 1])
      pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    else
      pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
  }

  // create main chain
  std::vector<int> main_chain;
  for (size_t i = 0; i < pairs.size(); i++) {
	  main_chain.push_back(pairs[i].first);
  }

  // recursve run until size got 1
  fJSort(main_chain);

  // create pend_chain
  std::vector<int> pend_chain;
  for (size_t j = 0; j < main_chain.size(); j++){
    for (size_t i = 0; i < pairs.size(); i++){
		if (pairs[i].first == main_chain[j])
		{
			pend_chain.push_back(pairs[i].second);
			break;
		}}}

  // insert first element of pend_chain because it b1 < a1 and a1 < a2 < a3 ...
  main_chain.insert(main_chain.begin(), pend_chain[0]);

  // get pend chain insert order from jacobsthal sequence
  std::vector<int> order = pendIsertOrderVec(pend_chain.size());

  //std::cout << "main_chain: ";
  //printRange(main_chain.begin(), main_chain.end());

  size_t insert_count = 1;
  for (size_t i = 0; i < order.size(); i++)
  {
	  //int worst_ak_pos = std::min(order[i]+insert_count, main_chain.size());
	  int worst_ak_pos = order[i]+insert_count;
	  binaryInsert(main_chain, main_chain.begin() + worst_ak_pos, pend_chain[order[i]-1]);
	  insert_count++;
  }
  if(straggler)
	  binaryInsert(main_chain, main_chain.end(), straggler);
  vec = main_chain;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: require positive integer sequence as an argumen!"
              << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    struct timeval start, end;
    std::vector<int> vec;
    std::deque<int> deq;

    validateInput(vec, argv);
    validateInput(deq, argv);

    std::cout << "Before: ";
    printRange(vec.begin(), vec.end());

    gettimeofday(&start, NULL);
	fJSort(vec);
    gettimeofday(&end, NULL);
    // print after

    std::cout << "After: ";
    printRange(vec.begin(), vec.end());



    std::cout << "Before: ";
    printRange(deq.begin(), deq.end());
    gettimeofday(&start, NULL);
    // run algo on deq
    gettimeofday(&end, NULL);
    // print after

    // print elapsed time interval

    // DEBUG
    // std::vector<int> order = pendIsertOrder(vec[0]);
    // printRange(order.begin(), order.end());

  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
