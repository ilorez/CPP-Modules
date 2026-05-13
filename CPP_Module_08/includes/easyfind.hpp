#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
#include <iterator>

template <typename T>
bool easyfind(T first, int second)
{
  typename T::iterator it;
  for ( it = first.begin(); it != first.end(); it++)
  {
    if (it->second == second)
    {
      std::cout << *it << std::endl;
      return true;
    }
  }
  return (false);
}

#endif
