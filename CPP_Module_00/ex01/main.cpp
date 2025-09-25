/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:56:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/25 19:36:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/container.hpp"
#include "includes/PhoneBook.hpp"
#include <cstdlib>

std::string ft_readline()
{
  std::string input;

  if (!std::getline(std::cin, input))
  {
    std::cout << std::endl << "reach EOF, exit program" << std::endl;
    exit(EXIT_FAILURE);
  }
  return input;
}

int main()
{
  int index;
  PhoneBook pb;
  std::string cmd;

  while(true)
  {
    std::cout << "Write a Command: ";
    cmd = ft_readline();
    if (cmd == "ADD")
        pb.add_new_contact();
    else if (cmd == "SEARCH")
    {
        if (pb.isempty())
          std::cout << "Your friends is 0 XD." << std::endl;
        else
        {
          pb.show_contacts_table(); 
          while (true)
          {
            std::cout << "write contact index to display, or 0 to back: ";
            index = std::atoi(ft_readline().c_str());
            if (pb.display_contact(index))
              break;
          }
        }
    }
    else if (cmd == "EXIT")
    {
      std::cout << "exit program" << std::endl;
      return (0);
    }
    else if (cmd == "test")
    {
      pb.display_contacts();
    }
    else
      std::cout << "command not found :<" << std::endl;
  }
}
