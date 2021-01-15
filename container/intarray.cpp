#include "intarray.h"
#include <iostream>
#include <cassert>

IntArray::IntArray(int length)
  : m_length{length} 
{
  assert(length >= 0);

  if (length > 0)
    m_data = new int[length] {};
}

IntArray::~IntArray() {
  if (m_data != nullptr)
    delete[] m_data;
}

int& IntArray::operator[] (int index) {
  assert(index >= 0 and index < m_length);
  return m_data[index];
}

void IntArray::erase() {
  if (m_data != nullptr)
    delete[] m_data;

  m_length = 0;
  m_data = nullptr;
  
  return;
}

void IntArray::reallocate(int newLength) {
  erase();

  if (newLength <= 0)
    return;

  m_data = new int[newLength];
  m_length = newLength;
}

void IntArray::resize(int newLength) {
  if (newLength == m_length)
    return;

  if (newLength <= 0) {
    erase();
    return;
  }

  int* data{ new int[newLength] };

  if (m_length > 0) {
    int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

    for (int i = 0; i < elementsToCopy; ++i) {
      data[i] = m_data[i];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
  }
}

void IntArray::insert(int value, int index) {
  assert(index >= 0 and index <= m_length);
  int* data{ new int[m_length + 1] };
  for (int i = 0; i < index; ++i)
    data[i] = m_data[i];

  data[index] = value;
  for (int i = index; i <= m_length; ++i)
    data[i + 1] = m_data[i];

  if (m_data != nullptr)
    delete[] m_data;

  m_data = data;
  ++m_length;
}

void IntArray::remove(int index) {
  assert(index >= 0 and index < m_length);
  if (m_length == 1) {
    erase();
    return;
  }

  int* data{ new int[m_length - 1] };

  for (int i = 0; i < index; ++i)
    data[i] = m_data[i];

  for (int i = index; i < m_length - 1; ++i)
    data[i] = m_data[i + 1];

  if (m_data != nullptr)
    delete[] m_data;

  m_data = data;
  --m_length;
}

void IntArray::insert_front(int value) {
  insert(value, 0);
}

void IntArray::insert_back(int value) {
  insert(value, m_length);
}

int IntArray::get_length() const {
  return m_length;
}