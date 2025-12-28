#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "iostream"

class ScalarConverter {
  private:
    // OCF not allowed here because:
    // this class is a utility class like (math, std ...)
    // have no state or attribute
    // its should not be instantiated...
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
  public:
    static void convert(const std::string &literal);

};

#endif
