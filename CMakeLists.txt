project(RESTcpp)

cmake_minimum_required(VERSION 2.8)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(BUILD_SHARED_LIBS ON)

include_directories("${PROJECT_SOURCE_DIR}/include")

# Main library
set(SOURCES src/Service.cpp)

add_library(restcpp ${SOURCES})

# Test driver
find_package(CppUnit REQUIRED)

set(TEST_SOURCES test/main.cpp)

add_executable(UnitTester ${TEST_SOURCES})

target_link_libraries(UnitTester restcpp
                                 cppunit)
