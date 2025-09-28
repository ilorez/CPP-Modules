/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:56:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/28 15:39:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
  std::string filename;
  std::string s1;
  std::string s2;

  if (ac != 4)
  {
    std::cerr << "Error: Require 3 argumnets" << std::endl;
    return (EXIT_FAILURE);
  }

  filename = av[1];
  s1 = av[2];
  s2 = av[3];

  // validate argumnets
  if (filename.empty() || s1.empty())
  {
    std::cerr << "Error: Argumnets filename and s1 should not be empty" << std::endl;
  }

  // open and readinput from file
  std::ifstream readFile(filename.c_str());
  if (!readFile.is_open()){
    std::cerr << "Error: Could not open the file!" << std::endl;
  }

  // read file content as string
  std::string line;
  std::string all_lines;
  while (std::getline(readFile, line))
    all_lines += line + "\n";

  // close read file
  readFile.close();

  // replace our targeted word
  size_t pos = 0;
  while ((pos = all_lines.find(s1, pos)) != std::string::npos)
  {
    all_lines.erase(pos, s1.length());
    all_lines.insert(pos, s2);
    pos += s2.length();
  }


  // put string to new file
  std::string new_filename = filename + ".replace";
  std::ofstream writeFile(new_filename.c_str());
  if (!writeFile.is_open()){
    std::cerr << "Error: Could not open the file!" << std::endl;
  }

  // write all line to the new open file
  writeFile << all_lines;

  // close
  writeFile.close();

  return (EXIT_SUCCESS);
}













//bool isEmpty(const std::string& str) {
//    for (size_t i = 0; i < str.length(); i++) {
//        if (!isspace(str[i])) {
//            return false; 
//        }
//    }
//    return true;
//}
