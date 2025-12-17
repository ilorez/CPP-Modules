/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/17 10:23:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
int main(void)
{
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  return 0;
}

/*int main( void ) {
  Fixed a;
  Fixed b;
  Fixed c;
  a = Fixed( 5 );
  b = Fixed( 2.5f );
  c = b * a;
  std::cout << "c is " << c.toFloat() << std::endl;
  return 0;
}*/


