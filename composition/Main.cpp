#include "point2D.h"
#include "creature.h"
#include <iostream>
#include <string>

int main()
{
  std::string name;
  std::cout << "Enter a name for your creature : ";
  std::cin >> name;
  std::cin.ignore();
  Creature creature(name, { 4, 7 });

  while (true)
  {
    std::cout << creature << std::endl;
    std::cout << "Enter new x-location (-1 to quit): ";
    int x{ 0 };
    std::cin >> x;
    if (x == -1)
      break;

    
    std::cout << "Enter new y-location (-1 to quit): ";
    int y{ 0 };
    std::cin >> y;
    if (y == -1)
      break;

    creature.moveTo(x, y);
  }
  



  return 0;
}