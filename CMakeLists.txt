project(RESTcpp)

cmake_minimum_required(VERSION 2.8)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(BUILD_SHARED_LIBS ON)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_definitions("-std=c++0x")

# Main library
find_package(Boost COMPONENTS signals REQUIRED)
find_package(OpenSSL REQUIRED)

set(SOURCES src/Service.cpp
            src/ShutdownManager.hpp)

add_library(restcpp ${SOURCES})

# Test driver
find_package(CppUnit REQUIRED)

set(TEST_SOURCES test/main.cpp)

add_executable(UnitTester ${TEST_SOURCES})

target_link_libraries(UnitTester restcpp
                                 cppunit)
