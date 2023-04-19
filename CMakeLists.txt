cmake_minimum_required(VERSION 3.21)
project(process_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.81.0 REQUIRED COMPONENTS filesystem system)
#find_package(GTest REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(main main.cpp)
add_dependencies(main reporter creator)
target_link_libraries(main ${Boost_LIBRARIES})

add_executable(creator creator.cpp)
target_link_libraries(creator ${Boost_LIBRARIES})

add_executable(reporter reporter.cpp)
target_link_libraries(reporter ${Boost_LIBRARIES})

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove main
        COMMAND ${CMAKE_COMMAND} -E remove creator
        COMMAND ${CMAKE_COMMAND} -E remove reporter
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/binFile/Users/kiriill/Desktops/*
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/reports/*
        )

