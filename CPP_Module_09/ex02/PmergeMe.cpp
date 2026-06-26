#include "./includes/PmergeMe.hpp"
#include <deque>

std::vector<int> pendIsertOrderVec(size_t size) {
	std::vector<int> js;
	std::vector<int> order;
    size_t current;
    js.push_back(1);
    js.push_back(1);
    js.push_back(3);

    // in case of there is just b1 b2 in pend chain
    if (size > 2)
      order.push_back(3);
    if (size > 1)
      order.push_back(2);
    for (size_t i = 3; i < size; i++) {
      // current = previous + 2 × (previous of the previous)
      current = js[i - 1] + 2 * js[i - 2];
      // for use later with next number in Jacob sequence
      js.push_back(current);
      // if found that next number in jacob sequence is large then
      // the number of elemenet we have in pend_chain we just start from
      // pend_chain size remember that the jacob sequence is used to get index,
      // no need for index that will not be used
      if (current > size)
        current = size;
      // we stop when we found "current" inside jacob arr
      // we can use find to do this
      // but we know also that the first element we will found is the element we
      // start counting down from it and that element is the js[-2] before last
      // element which is already stored in js
      while (current != static_cast<size_t>(*(js.end() - 2))) {
        order.push_back(current--);
        if (order.size() == size - 1)
          return order;
      }
    }
	return order;
};



std::deque<int> pendIsertOrderDeq(size_t size) {
	std::deque<int> js;
	std::deque<int> order;
    size_t current;
    js.push_back(1);
    js.push_back(1);
    js.push_back(3);

    if (size > 2)
      order.push_back(3);
    if (size > 1)
      order.push_back(2);
    for (size_t i = 3; i < size; i++) {
      current = js[i - 1] + 2 * js[i - 2];
      js.push_back(current);
      if (current > size)
        current = size;
      while (current != static_cast<size_t>(*(js.end() - 2))) {
        order.push_back(current--);
        if (order.size() == size - 1)
          return order;
      }
    }
	return order;
};


void fJSortVec(std::vector<int> &container) {
  // base stop rec
  if (container.size() == 1) {
    return;
  }

  std::vector<std::pair<int, int> > pairs;
  int straggler = 0;
  if (container.size() % 2) {
    straggler = container.back();
    container.pop_back();
  }

  // create pair list
  for (size_t i = 0; i < container.size(); i += 2) {
    // sort pair
    if (container[i] > container[i + 1])
      pairs.push_back(std::make_pair(container[i], container[i + 1]));
    else
      pairs.push_back(std::make_pair(container[i + 1], container[i]));
  }

  // create main chain
  std::vector<int> main_chain;
  for (size_t i = 0; i < pairs.size(); i++) {
	  main_chain.push_back(pairs[i].first);
  }

  // recursve run until size got 1
  fJSortVec(main_chain);

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
  container = main_chain;
}

void fJSortDeq(std::deque<int> &container) {
  if (container.size() == 1) {
    return;
  }

  std::deque<std::pair<int, int> > pairs;
  int straggler = 0;
  if (container.size() % 2) {
    straggler = container.back();
    container.pop_back();
  }
  for (size_t i = 0; i < container.size(); i += 2) {
    if (container[i] > container[i + 1])
      pairs.push_back(std::make_pair(container[i], container[i + 1]));
    else
      pairs.push_back(std::make_pair(container[i + 1], container[i]));
  }
  std::deque<int> main_chain;
  for (size_t i = 0; i < pairs.size(); i++) {
	  main_chain.push_back(pairs[i].first);
  }
  fJSortDeq(main_chain);
  std::deque<int> pend_chain;
  for (size_t j = 0; j < main_chain.size(); j++){
    for (size_t i = 0; i < pairs.size(); i++){
		if (pairs[i].first == main_chain[j])
		{
			pend_chain.push_back(pairs[i].second);
			break;
		}}}

  main_chain.insert(main_chain.begin(), pend_chain[0]);

  std::deque<int> order = pendIsertOrderDeq(pend_chain.size());
  size_t insert_count = 1;
  for (size_t i = 0; i < order.size(); i++)
  {
	  int worst_ak_pos = order[i]+insert_count;
	  binaryInsert(main_chain, main_chain.begin() + worst_ak_pos, pend_chain[order[i]-1]);
	  insert_count++;
  }
  if(straggler)
	  binaryInsert(main_chain, main_chain.end(), straggler);
  container = main_chain;
}

void displayInterval(std::string container_name, size_t size, struct timeval &start,  struct timeval &end) {
    double elapsed =
        (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << size 
              << " elements with std::" << container_name << " : " << elapsed
              << " us" << std::endl;
  }
