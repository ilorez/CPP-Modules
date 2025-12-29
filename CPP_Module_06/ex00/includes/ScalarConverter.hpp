/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:57:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/29 13:53:25 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "./Container.hpp"

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
