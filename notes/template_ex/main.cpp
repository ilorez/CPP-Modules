/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:09:42 by znajdaou          #+#    #+#             */
/*   Updated: 2026/05/13 14:41:38 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/Container.hpp"
template <typename T>
void foo(const T& x)
{
  std::cout << "const" << std::endl;
  std::cout << x << std::endl;
}

template <typename T>
void foo(T& x)
{
  std::cout << "non const" << std::endl;
  x = 42;
  std::cout << x << std::endl;
}

// -------- My tests
//*
int main()
{
  int x = 5;
  foo(x);
  const int y = 6;
  foo(y);
  return 0;
}
// */

