/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:56:50 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/29 12:56:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"

bool isValid(const std::string &s)
{
  if (s.empty())
         return (false);
  for (size_t i = 0; i < s.length(); i++)
  {
    if (s[i] < 32 || s[i] > 126)
      return (false);
  }
  return (true);
}

bool isChar(const std::string &s)
{
  if (s.length() == 1 && (s[0] < 48 || s[0] > 57))
    return (true);
  return (false);
}

bool isInt(const std::string &s)
{
  size_t i = 0;
  if (s[i] == '-' || s[i] == '+')
    i++;
  if (i == s.length())
    return false;
  for (; i < s.length(); i++)
  {
    if (!std::isdigit(s[i]))
      return false;
  }
  return (true);
}

bool isFloat(const std::string &s)
{
  // i decide to now check on dot a say this is a float just by adding a f at end
  if (s[s.length() - 1] == 'f')
    return true;
  return false;
}

t_type getType(const std::string &s)
{
  if (!s.compare("-inff") || !s.compare("+inff") || !s.compare("nanf"))
    return (TPSEUDOF);
  if (!s.compare("-inf") || !s.compare("+inf") || !s.compare("nan"))
    return (TPSEUDOD);
  if (isChar(s))
    return (TCHAR);
  if (isInt(s))
    return (TINT);
  if (isFloat(s))
    return (TFLOAT);
  return (TDOUBLE);
}

void printChar(int c)
{
  if (c > std::numeric_limits<char>::max() ||
      c < std::numeric_limits<char>::min())
    std::cout << "char: impossible" << std::endl;
  else if (c < 32 || c > 126)
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '"<< (char)c << "'" << std::endl;
}

void printImpossible(int n)
{
    std::cout << "char: impossible" << std::endl;
    --n && std::cout << "int: impossible" << std::endl;
    n && --n && std::cout << "float: impossible" << std::endl;
    n && --n && std::cout << "double: impossible" << std::endl;
}

bool getInt(const std::string &s, int &v)
{
  char c;
  std::stringstream ss(s);
  if (!(ss >> v) || (ss >> c))
    return false;
  return true;
}

bool getFloat(const std::string &s, float &v)
{
  char c;
  std::stringstream ss(s.substr(0, s.length() - 1));
  if (!(ss >> v) || (ss >> c))
    return false;
  return true;
}

bool getDouble(const std::string &s, double &v)
{
  char c;
  std::stringstream ss(s);

  if (!(ss >> v) || (ss >> c))
    return false;
  return true;
}
