/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:58:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/11/13 16:57:10 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 
  private:
    int _value;
    static const int _fract_bits = 8;
  public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int value);
    Fixed(const float value);
    Fixed& operator=(const Fixed& copy);
    ~Fixed();
    // new operators
    // comparison 
    bool operator>(const Fixed& x) const;
    bool operator<(const Fixed& x) const;
    bool operator>=(const Fixed& x) const;
    bool operator<=(const Fixed& x) const;
    bool operator==(const Fixed& x) const;
    bool operator!=(const Fixed& x) const;
    // arithmetic
    Fixed operator+(const Fixed& right) const;
    Fixed operator-(const Fixed& right) const;
    Fixed operator*(const Fixed& right) const;
    Fixed operator/(const Fixed& right) const;
    // (pre/post)increment/decrement
    
  
    float toFloat(void) const;
    float toInt(void) const;
  
    int getRawBits(void) const;
    void setRawBits(const int vlaue);
};


std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
