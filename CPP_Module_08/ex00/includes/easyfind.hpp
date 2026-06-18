#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
bool easyfind(const T& first, int second)
{
  return std::find(first.begin(), first.end(), second) != first.end();
}

#endif
