#include <string>
#include <iostream>

class Car
{
private:
  std::string m_name;
  int m_id;

public:
  Car(const std::string& name, int id)
    : m_name{ name }, m_id{ id }
  {

  }

  const std::string& getName() const { return m_name; };
  int getId() { return m_id; };
};

class CarLot {
private:
  static Car s_carLot[4];

public:
  CarLot() = delete;

  static Car* getCar(int id)
  {
    for (int count{ 0 }; count < 4; ++count)
      if (s_carLot[count].getId() == id)
        return &s_carLot[count];
    
    return nullptr;
  }
};

Car CarLot::s_carLot[4]{
  {"Prius", 4}, {"Corolla", 17}, {"Accord", 84}, {"Matrix", 62},
};

class Driver
{
private:
  std::string m_name;
  int m_carId;

public:
  Driver(const std::string& name, int carId)
    : m_name{ name }, m_carId{ carId }
  {

  }

  const std::string& getName() const { return m_name; }
  int getCarId() const { return m_carId; }
};

int main() {
  Driver d{ "Zaky", 17 };

  Car* car{ CarLot::getCar(d.getCarId()) };

  if (car)
    std::cout << d.getName() << " is driving a " << car->getName() << std::endl;
  else
    std::cout << d.getName() << " could'nt find his car" << std::endl;



  return 0;
}