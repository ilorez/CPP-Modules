#include "./includes/PmergeMe.hpp"

std::vector<int> pendIsertOrder(size_t size) {
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


