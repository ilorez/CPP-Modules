/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:58:37 by znajdaou          #+#    #+#             */
/*   Updated: 2025/10/01 17:27:10 by znajdaou         ###   ########.fr       */
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
  Fixed(Fixed &copy);
  Fixed& operator=(const Fixed& copy);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(const int vlaue);
};

#endif
