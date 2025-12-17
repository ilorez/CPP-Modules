#include "Point.hpp"

// default constructor
Point::Point():_x(0), _y(0) {};
// destructor
Point::~Point(){};
// constructor 2
Point::Point(const float x, const float y):_x(x), _y(y){};
// copy constructor
Point::Point(const Point &copy):_x(copy._x), _y(copy._y){};
// copy assignment operator overload
//Point Point::operator=(const Point &copy){}:_x(copy._x), _y(copy._y){;
Point& Point::operator=(const Point &copy)
{
  (void)copy;
  return (*this);
}

// getters
Fixed Point::getX(void) const
{
  return (_x);
}

Fixed Point::getY(void) const
{
  return (_y);
}
