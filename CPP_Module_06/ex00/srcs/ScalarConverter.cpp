#include "../includes/ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>

enum t_type {
  TCHAR,
  TINT,
  TFLOAT,
  TDOUBLE,
  UNKONW
};

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
  (void)s;
  return (false);
}

bool isDouble(const std::string &s)
{
  (void)s;
  return (false);
}

t_type getType(const std::string &s)
{
  if (!s.compare("-inff") || !s.compare("+inff") || !s.compare("nanf"))
    return (TFLOAT);
  if (!s.compare("-inf") || !s.compare("+inf") || !s.compare("nan"))
    return (TDOUBLE);
  if (isChar(s))
    return (TCHAR);
  if (isInt(s))
    return (TINT);
  if (isFloat(s))
    return (TFLOAT);
  if (isDouble(s))
    return (TDOUBLE);
  return (UNKONW);
}

void printChar(char c)
{
  if (c < 32 || c > 126)
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '"<< c << "'" << std::endl;

}
void printIt(char c, int i, float &f, double &d)
{
  printChar(c);
  std::cout << "int: "<< i << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: "<< f << "f" << std::endl;
  std::cout << "double: "<< d << std::endl;
}


void printInt(const std::string &s)
{
  long long value = std::atoll(s.c_str());
  int i =  static_cast<int>(value);
  if (value > std::numeric_limits<int>::max() ||
      value < std::numeric_limits<int>::min()
  )
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
  }
  else if (value > std::numeric_limits<char>::max() ||
      value < std::numeric_limits<char>::min()
  )
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  }
  else {
    printChar(static_cast<char>(i));
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  }
  std::cout << std::fixed << std::setprecision(1);
  float f = static_cast<float>(i);
  double d = static_cast<double>(i);
  std::cout << "float: "<< f << "f" << std::endl;
  std::cout << "double: "<< d << std::endl;
}


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

  char c;
  int i;
  float f;
  double d;
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
    case TCHAR:
      c = str[0];
      i = static_cast<int>(c);
      f = static_cast<float>(c);
      d = static_cast<double>(c);
      printIt(c, i, f,d);
      break;
    case TINT:
      printInt(str);
      break;
    case TFLOAT:
      break;
    case TDOUBLE:
      break;
    default:
      std::cerr << "Invalid input" << std::endl;
  }
}

