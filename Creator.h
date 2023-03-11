//
// Created by Kirill on 11.03.2023.
//

#ifndef OS_LAB1__CREATOR_H_
#define OS_LAB1__CREATOR_H_

#include <iostream>
#include <fstream>
#include <string>

struct Employee {
  Employee(int num, char *name, double hours) : num_(num),
                                                hours_(hours) {
    for (int i = 0; i < 10; i++) {
      name_[i] = name[i];
    }
  };
  int num_;        // идентификационный номер сотрудника
  char name_[10];  // имя сотрудника
  double hours_;   // количество отработанных часов
};

Employee createNewEmployee() {
  int num;
  std::string name;
  double hours;

  std::cout << "Enter employee identification number: ";
  std::cin >> num;
  std::cout << "Enter employee name: ";
  std::cin >> name;
  while (name.size() > 10) {
    std::cout << "Enter employee name (max 10 letters): ";
    std::cin >> name;
  }
  std::cout << "Enter employee hours worked: ";
  std::cin >> hours;

  return {num, reinterpret_cast<char *>(&name), hours};
}

void createFile() {
  std::string fileName;
  int numOfRequests;
  std::cout << "Enter file name: ";
  std::cin >> fileName;
  std::cout << "Enter num of requests: ";
  std::cin >> numOfRequests;

  std::ofstream outfile
      ("./Employees/" + fileName + ".bin", std::ios::out | std::ios::binary);

  if (!outfile) {
    std::cerr << "Error: Cannot create file " << fileName << ".bin"
              << std::endl;
    return;
  }

  for(int i = 0; i < numOfRequests; i++) {
    Employee e = createNewEmployee();
    outfile.write(reinterpret_cast<const char *>(&e.num_), sizeof(e.num_));
    outfile.write(reinterpret_cast<const char *>(&e.name_), sizeof(e.name_));
    outfile.write(reinterpret_cast<const char *>(&e.hours_), sizeof(e.hours_));
  }

  outfile.close();
}

void deleteEmployee() {
  std::string fileName;
  int num;
  std::cout << "employee identification number to delete: ";
  std::cin >> num;

  fileName = ("./Employees/" + std::to_string(num) + ".bin");

  int result = std::remove(reinterpret_cast<char *>(&fileName));
  if (result == 0) {
    std::cout << "File deleted successfully!" << std::endl;
  }
  else {
    std::cout << "Error: Unable to delete file." << std::endl;
  }
}

#endif //OS_LAB1__CREATOR_H_
