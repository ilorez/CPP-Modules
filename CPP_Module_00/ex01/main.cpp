/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:56:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/24 18:59:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/container.hpp"

int main()
{
  Contact a;
  a.setFirstName("zobair");
  std::string cmd;
  while(1)
  {
    std::cout << "Write a Command: ";
    if (!std::getline(std::cin, cmd))
    {
      std::cout << std::endl << "reach EOF, exit program" << std::endl;
      return (0);
    }
    if (cmd == "ADD")
        ;
    else if (cmd == "SEARCH")
        ;
    else if (cmd == "EXIT")
    {
      std::cout << "exit program" << std::endl;
      return (0);
    }
    else if (cmd == "test")
      std::cout << "first name is :" << a.getFirstName() << std::endl;
      
    else
      std::cout << "command not found :<" << std::endl;
  }
}
