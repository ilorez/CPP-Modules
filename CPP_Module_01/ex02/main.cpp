/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:09:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/27 23:16:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main()
{
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "----------------------" << std::endl;
  std::cout << "_________mem add str: " << &str << std::endl;
  std::cout << "mem add held by *str: " << stringPTR << std::endl;
  std::cout << "mem add held by &str: " << &stringREF << std::endl;

  std::cout << "----------------------" << std::endl;
  std::cout << "_str value: " << str << std::endl;
  std::cout << "*str value: " << *stringPTR << std::endl;
  std::cout << "&str value: " << stringREF << std::endl;
}
