/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:58:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/10/01 18:32:15 by znajdaou         ###   ########.fr       */
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
  
    float toFloat(void) const;
    float toInt(void) const;
  
    int getRawBits(void) const;
    void setRawBits(const int vlaue);
};


std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
