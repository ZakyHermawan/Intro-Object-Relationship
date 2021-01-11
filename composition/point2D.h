#pragma once
#include <iostream>

class Point2D
{
private:
  int m_x;
  int m_y;

public:
  Point2D(int x=0, int y=0)
    : m_x{ 0 }, m_y{ 0 }
  {

  }

  friend std::ostream& operator<< (std::ostream& out, const Point2D& point);

  void setPoint(int& x, int& y);

};




