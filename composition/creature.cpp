#include "creature.h"
#include "point2D.h"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const Creature& creature)
{
  out << creature.m_name << " is located at " << creature.m_location << std::endl;
  return out;
}

void Creature::moveTo(int x, int y)
{
  m_location.setPoint(x, y);
  return;
}
