#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cstdint>

class Patient;

class Doctor
{
private:
  std::string m_name{};
  std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
  Doctor(const std::string& name)
    : m_name{ name }
  {

  }

  void addPatient(Patient& patient);
  const std::string& getName() const;

  friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

};


class Patient
{
private:
  std::string m_name{};
  std::vector<std::reference_wrapper<const Doctor>> m_doctor{};

  void addDoctor(const Doctor& doctor);

public:
  Patient(const std::string& name)
    : m_name{ name }
  {

  }

  const std::string& getName() const;

  friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

  friend void Doctor::addPatient(Patient& patient);
};




void Patient::addDoctor(const Doctor& doctor)
{
  m_doctor.push_back(doctor);
}

void Doctor::addPatient(Patient& patient)
{
  m_patient.push_back(patient);
  patient.addDoctor(*this);
}

const std::string& Doctor::getName() const
{
  return m_name;
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
  if (doctor.m_patient.empty())
  {
    out << doctor.m_name << " has no patient right now";
    return out;
  }

  std::cout << doctor.m_name << " is seeing patients: ";

  for (const auto& patient : doctor.m_patient)
    out << patient.get().getName() << " ";
  return out;
}


const std::string& Patient::getName() const
{
  return m_name;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
  if (patient.m_doctor.empty())
  {
    out << patient.m_name << " has no doctor right now";
    return out;
  }

  std::cout << patient.m_name << " is seeing doctors:  ";
  for (const auto& doctor : patient.m_doctor)
    out << doctor.get().getName() << ' ';
  return out;
}

int main()
{
  Patient dave{ "Dave" };
  Patient frank{ "Frank" };
  Patient betsy{ "Betsy" };

  Doctor james{ "James" };
  Doctor scott{ "Scott" };

  james.addPatient(dave);

  scott.addPatient(dave);
  scott.addPatient(betsy);

  std::cout << james << std::endl;
  std::cout << scott << std::endl;
  std::cout << dave << std::endl;
  std::cout << frank << std::endl;
  std::cout << betsy << std::endl;


  return 0;
}

