project(RESTcpp)

cmake_minimum_required(VERSION 2.8)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(BUILD_SHARED_LIBS ON)

include_directories("${PROJECT_SOURCE_DIR}/include"
                    "${PROJECT_SOURCE_DIR}/src"
                     ${GOOGLEMOCK_INCLUDE_DIR}
                    )

add_definitions("-std=c++0x")

# Main library
find_package(Boost COMPONENTS system thread REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Log4CPP REQUIRED)
find_package(GoogleMock REQUIRED)
find_package(GoogleTest REQUIRED)
find_package(OpenSSL REQUIRED)

set(SOURCES src/Service.cpp
            src/ShutdownManager.hpp
            src/Server.cpp
            )

add_library(restcpp ${SOURCES})

target_link_libraries(restcpp pion-net
                              pion-common
                              ${Boost_SYSTEM_LIBRARY}
                              ${Boost_THREAD_LIBRARY}
                              ${LOG4CPP_LIBRARIES}
                              ${OPENSSL_LIBRARIES}
                              pthread
                              )

# Test driver
find_package(CppUnit REQUIRED)

set(TEST_SOURCES test/main.cpp
                 test/ServiceTest.cpp)

add_executable(UnitTester ${TEST_SOURCES})

target_link_libraries(UnitTester restcpp
                                 cppunit
                                 ${GOOGLEMOCK_LIBRARY}
                                 ${GTEST_LIBRARIES}
                                 )
