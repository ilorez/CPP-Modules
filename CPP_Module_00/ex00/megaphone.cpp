/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:00:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/08 11:32:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void put_uppertext(std::string);
int is_lower_char(char);

int main(int ac, char **av)
{
  int i;

  if (ac > 1)
  {
    i = 1;
    while (av[i])
      put_uppertext(av[i++]);
  }
  else 
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  std::cout << "\n";
  return (0);
}

void put_uppertext(std::string text)
{
  int i;

  i = -1;
  while (text[++i])
    if (is_lower_char(text[i]))
      text[i] = text[i] - 32;
  std::cout << text;
}

int is_lower_char(char c)
{
  return (c > 96 && c < 123);
}

