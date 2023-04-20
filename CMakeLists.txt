cmake_minimum_required(VERSION 3.21)
project(threads_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.81.0 REQUIRED COMPONENTS system thread)
find_package(GTest REQUIRED)

include_directories(${Boost_INCLUDE_DIRS}, ${gtest_INCLUDE_DIRS})

add_executable(main main.cpp interface.h interface.cpp)
target_link_libraries(main ${Boost_LIBRARIES})

add_executable(test mainTest.cpp interface.h interface.cpp)
target_link_libraries(test GTest::GTest GTest::Main ${Boost_LIBRARIES})
