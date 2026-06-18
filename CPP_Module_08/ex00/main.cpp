#include "./includes/easyfind.hpp"
#include <vector>
#include <iostream>


int main()
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  if (easyfind(v, 2))
    std::cout << "found" << std::endl;
  else
    std::cout << "not found" << std::endl;
}
