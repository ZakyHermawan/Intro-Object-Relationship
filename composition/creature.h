#pragma once
#include "point2D.h"
#include <iostream>
#include <string>

class Creature
{
private:
  std::string m_name;
  Point2D m_location;

public:
  Creature(std::string name, Point2D location)
    : m_name{ name }, m_location{ location }
  {

  }

  friend std::ostream& operator<< (std::ostream& out, const Creature& creature);

  void moveTo(int x, int y);
};