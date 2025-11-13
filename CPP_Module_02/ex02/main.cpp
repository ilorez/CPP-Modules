/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/11/13 16:51:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
int main( void ) {
  Fixed a;
  Fixed b;
  Fixed c;
  a = Fixed( 5 );
  b = Fixed( 2.5f );
  c = b * a;
  std::cout << "c is " << c.toFloat() << std::endl;
  return 0;
}

