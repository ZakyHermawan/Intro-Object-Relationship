#pragma once
#include <initializer_list>

class IntArray
{
private:
  int m_length{};
  int* m_data{};

public:
  IntArray() = default;
  IntArray(int length);
  IntArray(std::initializer_list<int> list);

  ~IntArray();

  void erase();

  int& operator[] (int index);

  void reallocate(int newLength);

  void resize(int newLength);

  void insert(int value, int index);

  void remove(int index);

  void insert_front(int value);
  void insert_back(int value);

  int get_length() const;

};
