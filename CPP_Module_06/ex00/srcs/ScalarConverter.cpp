/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:34:50 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/29 12:53:45 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/helpers.h"


void ScalarConverter::convert(const std::string &str)
{
  // check if it is valid input
    // - all chars are printable
    // - not empty
  if (!isValid(str))
  {
    std::cerr << "invalid Input" << std::endl;
    return;
  }
  // used for foce decimal format and set number of digits after "."
  std::cout << std::fixed << std::setprecision(1);
  bool found = false;
  char c = 0;
  int i = 0;
  float f = 0;
  double d = 0;
  // get the type of the input
  // use switch to print types
    // first convert it from string to its type using cpp explicity conversion 
    // and then to the three other types
  //
  //
  // TODO:
  //  what I'm doing now is worng
  //  i need some checks for int type to print impossible in case of overflow
  switch (getType(str))
  {
    case TPSEUDOF:
      printImpossible(2);
      std::cout << "float: " << str << std::endl;
      std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
      break;
    case TPSEUDOD:
      printImpossible(2);
      std::cout << "float: " << str << "f" << std::endl;
      std::cout << "double: " << str << std::endl;
      break;
    case TCHAR:
      DEBUG_INFO("Type: char");
      c = str[0];
      i = static_cast<int>(c);
      f = static_cast<float>(c);
      d = static_cast<double>(c);
      found = true;
      printChar(i);
    case TINT:
      if (!found)
      {
        DEBUG_INFO("Type: int");
        found = getInt(str, i);
        if (!found)
          return (printImpossible(4));
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        printChar(i);
      }
      std::cout << "int: "<< i << std::endl;
    case TFLOAT:
      if (!found)
      {
        DEBUG_INFO("Type: float");
        found = getFloat(str, f);
        if (!found)
          return (printImpossible(4));
        if (f > (float)INT_MAX || f < (float)INT_MIN)
          printImpossible(2);
        else
        {
          i = static_cast<int>(f);
          printChar(i);
          std::cout << "int: "<< i << std::endl;
        }
        d = static_cast<double>(f);
      }
      std::cout << "float: "<< f << "f" << std::endl;
    case TDOUBLE:
      if (!found)
      {
        DEBUG_INFO("Type: double");
        found = getDouble(str, d);
        if (!found)
          return (printImpossible(4));
        f = static_cast<float>(d);
        if (d > std::numeric_limits<float>::max() ||
            d < -std::numeric_limits<float>::max())
          printImpossible(3);
        else if (f > (float)INT_MAX || f < (float)INT_MIN)
        {
          printImpossible(2);
          std::cout << "float: "<< f << "f" << std::endl;
        }
        else
        {
          i = static_cast<int>(f);
          printChar(i);
          std::cout << "int: "<< i << std::endl;
          std::cout << "float: "<< f << "f" << std::endl;
        }
      }
      std::cout << "double: "<< d << std::endl;
      break;
    default:
      DEBUG_ERROR("Error");
      std::cerr << "Invalid input" << std::endl;
  }
}
