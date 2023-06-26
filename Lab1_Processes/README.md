## Project Name
Lab1_Processes

 ## Project Description
For this laboratory work, you need to write three console programs: Main, Creator, and Reporter.

The Creator program creates a binary file, whose name and number of records are specified via the command line. The records are entered from the console and have a specific structure containing information about employees.

The Reporter program creates a text file that contains an ordered list of employees with their corresponding salaries. The report is generated based on the binary file created by the Creator program.

 ## Project Files
The project contains the following files:
-  `main.cpp` : This file handles user input and calls Creator and Reporter components.
-  `creator.cpp` : This file contains the implementation for the Creator component to generate binary files with employee data.
-  `reporter.cpp` : This file contains the implementation for the Reporter component to generate payroll reports.
-  `Employee.h` : This file contains the Employee struct, which is used in the Creator and Reporter components to create and access employee data.
-  `CMakeLists.txt` : This file is used by CMake to generate the Makefile for building the project.
 ## Usage
Follow the instructions below to use the Payroll System:
- Clone the repository to your local machine.
- Install Boost libraries on your machine.
- Run the following command to build the project:  `cmake . && make` 
- Run the executable  `./main` .
- Enter the binary file name and the record count to generate employee data using Creator component.
- Enter the file name for the payroll report and pay per hour using Reporter component.
- The system will generate a payroll report in reports directory.
 ## Dependencies
The project has the following dependencies:
- Boost library
- CMake
 ## Contributors
- [Zavadsky Kirill](https://github.com/Kiriller102)