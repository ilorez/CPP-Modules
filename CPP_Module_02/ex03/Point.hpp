/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:39:52 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/17 16:31:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 
  private:
    const Fixed _x;
    const Fixed _y;
  public:
    Point();
    Point(const Point &copy);
    Point(const float x, const float y);
    Point& operator=(const Point& copy);
    ~Point();
    Fixed getX(void) const;
    Fixed getY(void) const;
};
#endif
