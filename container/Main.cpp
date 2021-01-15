#include "intarray.h"
#include <iostream>

int main()
{
  IntArray array(10);
  for (int i = 0; i < 10; ++i) {
    array[i] = i + 1;
  }

  array.resize(8);

  array.insert(10, 5);
  array.remove(3);

  array.insert_back(30);
  array.insert_front(40);

  for (int i = 0; i < array.get_length(); ++i) {
    std::cout << array[i] << std::endl;
  }

  return 0;
}