/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/10/01 18:41:25 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
  std::cout << "Default constructor called" << std::endl;
  _value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed::Fixed(const int value) {

  std::cout << "Int constructor called" << std::endl;
  _value = value << _fract_bits;
}

Fixed::Fixed(const float value) {

  std::cout << "Float constructor called" << std::endl;
  _value = roundf(value * (1 << _fract_bits));
}


Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy)
    _value = copy._value;
  return (*this);
}

void Fixed::setRawBits(int const value)
{
  std::cout << "setRawBits member function called" << std::endl;
  _value = value;
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return (_value);
}



float Fixed::toFloat(void) const
{
  return ((float)_value / (1<<_fract_bits));
}

float Fixed::toInt(void) const
{
  return (_value >> _fract_bits);
}


std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
  os << obj.toFloat();
  return (os);
}

