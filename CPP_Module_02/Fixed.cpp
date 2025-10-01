/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/10/01 17:31:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
  std::cout << "Default constructor called" << std::endl;
  _value = 0;
}

Fixed::Fixed(Fixed &copy)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy)
    _value = copy.getRawBits();
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
  
