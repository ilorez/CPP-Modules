/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2025/10/01 16:18:32 by znajdaou          #+#    #+#             */ /*   Updated: 2025/11/13 15:52:29 by znajdaou         ###   ########.fr       */ /*                                                                            */ /* ************************************************************************** */
#include "Fixed.hpp"
#include <cmath>

// default constructor
Fixed::Fixed()
{
  _value = 0;
}

// copy constructor
Fixed::Fixed(const Fixed &copy)
{
  *this = copy;
}

Fixed::Fixed(const int value) {

  _value = value << _fract_bits;
}

Fixed::Fixed(const float value) {

  _value = roundf(value * (1 << _fract_bits));
}


Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& copy) {
  if (this != &copy)
    _value = copy._value;
  return (*this);
}

void Fixed::setRawBits(int const value)
{
  _value = value;
}

int Fixed::getRawBits(void) const
{
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
// new operators
// comparison
// >
bool Fixed::operator>(const Fixed& x) const
{
  return (this->getRawBits() > x.getRawBits());
}
// <
bool Fixed::operator<(const Fixed& x) const
{
  return (this->getRawBits() < x.getRawBits());
}
// <=
bool Fixed::operator<=(const Fixed& x) const
{
  return (this->getRawBits() <= x.getRawBits());
}
// >=
bool Fixed::operator>=(const Fixed& x) const
{
  return (this->getRawBits() >= x.getRawBits());
}
// ==
bool Fixed::operator==(const Fixed& x) const
{
  return (this->getRawBits() == x.getRawBits());
}
// !=
bool Fixed::operator!=(const Fixed& x) const
{
  return (this->getRawBits() != x.getRawBits());
}


// arthmetic 
Fixed Fixed::operator+(const Fixed& right) const {
  Fixed tmp;
  tmp.setRawBits(this->getRawBits() + right.getRawBits());
  return (tmp);
}

// subtraction
Fixed Fixed::operator-(const Fixed& right) const {
    Fixed tmp;
    tmp.setRawBits(this->getRawBits() - right.getRawBits());
    return tmp;
}

// multiplication (needs scaling)
Fixed Fixed::operator*(const Fixed& right) const {
    Fixed tmp;
    tmp.setRawBits((this->getRawBits() * right.getRawBits()) >> _fract_bits);
    return tmp;
}

// division (needs scaling)
Fixed Fixed::operator/(const Fixed& right) const {
    Fixed tmp;
    tmp.setRawBits((this->getRawBits() << _fract_bits) / right.getRawBits());
    return tmp;
}
