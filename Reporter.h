//
// Created by Kirill on 11.03.2023.
//

#ifndef OS_LAB1__REPORTER_H_
#define OS_LAB1__REPORTER_H_

#include <iostream>
#include <fstream>

void createReport() {
  std::string fileToRead;
  std::string fileToWrite;
  int payment;

  std::cout << "Enter file to read name: ";
  std::cin >> fileToRead;
  std::cout << "Enter report name: ";
  std::cin >> fileToWrite;
  std::cout << "Enter payment: ";
  std::cin >> payment;

  std::ifstream inFile("./Employees/" + fileToRead + ".bin", std::ios::binary);

  if (inFile) {
    inFile.seekg(0, std::ios::beg);

    std::ofstream outFile
        ("./Employees/" + fileToWrite + ".txt",
         std::ios::out | std::ios::binary);

    if (!outFile) {
      std::cerr << "Error: Cannot create file " << fileToWrite << ".txt"
                << std::endl;
      return;
    }
    std::string title = "Report on the file \"" + fileToRead + '\"';
    outFile << title << '\n';

    while (inFile) {
      int num;
      char name[10];
      double hour;

      inFile.read(reinterpret_cast<char *>(&num), sizeof(num));
      inFile.read(reinterpret_cast<char *>(&name), sizeof(name));
      inFile.read(reinterpret_cast<char *>(&hour), sizeof(hour));
      if (inFile) {
        outFile << num << ' ' << name << ' ' << hour << ' ' << hour * payment << '\n';
      }
    }
    inFile.close();
  } else {
    std::cout << "Error: Unable to open file." << std::endl;
  }
}

void deleteReport() {
  std::string fileName;
  int num;
  std::cout << "Enter report file name to delete: ";
  std::cin >> num;

  fileName = ("./Employees/" + std::to_string(num) + ".txt");

  int result = std::remove(reinterpret_cast<char *>(&fileName));
  if (result == 0) {
    std::cout << "File deleted successfully!" << std::endl;
  }
  else {
    std::cout << "Error: Unable to delete file." << std::endl;
  }
}

#endif //OS_LAB1__REPORTER_H_
