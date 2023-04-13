cmake_minimum_required(VERSION 3.21)
project(process_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.81.0 REQUIRED COMPONENTS filesystem system)
find_package(GTest REQUIRED)

include_directories(${Boost_INCLUDE_DIRS}, ${gtest_INCLUDE_DIRS})

add_executable(tests mainTests.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)

add_executable(main main.cpp)
target_link_libraries(main ${Boost_LIBRARIES})

add_executable(creator creator.cpp)
target_link_libraries(creator ${Boost_LIBRARIES})

add_executable(reporter reporter.cpp)
target_link_libraries(reporter ${Boost_LIBRARIES})

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/creator")
    message(STATUS "creator not found, building it...")

    # Зависимость для создания creator перед запуском main
    add_dependencies(main creator)
endif()

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/reporter")
    message(STATUS "creator not found, building it...")

    # Зависимость для создания reporter перед запуском main
    add_dependencies(main reporter)
endif()

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove main
        COMMAND ${CMAKE_COMMAND} -E remove creator
        COMMAND ${CMAKE_COMMAND} -E remove reporter
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/binFiles/*
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/reports/*
        )

