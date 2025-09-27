/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:26:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/27 23:04:25 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
  Zombie *z = new Zombie[N];
  for (int i = 0; i < N; i++)
  {
    z[i].setZombieName(name);
  }
  return (z);
}
