
#include "Point.hpp"

Fixed sign(Point const& p1, Point const& p2, Point const& p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
         - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
  Fixed l1 = sign(point, a, b);
  Fixed l2 = sign(point, b, c);
  Fixed l3 = sign(point, c, a);
  if ((l1 < 0 && l2 < 0 && l3 < 0)
    || (l1 > 0 && l2 > 0 && l3 > 0))
    return true;
  return false;
}
