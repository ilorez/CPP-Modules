/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:26:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/11/05 10:59:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name )
{
  if (N <= 0)
  {
    exit(EXIT_FAILURE);
  }
  Zombie *z = new Zombie[N];
  for (int i = 0; i < N; i++)
  {
    z[i].setZombieName(name);
  }
  return (z);
}
