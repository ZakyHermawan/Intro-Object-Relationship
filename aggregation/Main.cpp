#include <iostream>
#include <string>

class Teacher
{
private:
  std::string m_name{};

public:
  Teacher(const std::string& name)
    : m_name{ name }
  {

  }

  const std::string& getName() const { return m_name; };
};

class Department
{
private:
  const Teacher& m_teacher;

public:
  Department(const Teacher& teacher)
    : m_teacher{ teacher }
  {

  }
};



int main()
{
  Teacher bob{ "Bob" };
  {
    Department department{ bob };
  } // when the teacher is department is destroyed, the teacher(bob) is not destroyed
  
  std::cout << bob.getName() << std::endl;

  return 0;
}