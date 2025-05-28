/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:00:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/25 21:00:54 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
  int i;

  if (ac > 1)
  {
    i = 1;
    while (av[i])
      std::cout << av[i++];
  }
  else 
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  std::cout << "\n";
  return (0);
}
