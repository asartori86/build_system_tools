cmake_minimum_required(VERSION 3.9)

set(name how_to_test_02)

project(${name} CXX)

add_executable(${name} main.cc)

include_directories(include)

add_definitions("-std=c++11")

add_subdirectory(src)

# it must be in the same file where the executable has been defined
target_link_libraries(${name} mathematics physics)

enable_testing()

set(GTEST_DIR "" CACHE STRING "google test dir")

find_path(GTEST_INC_DIR "gtest/gtest.h"
  HINTS
  ${GTEST_DIR}/include
  ${GTEST_DIR}/googletest/include)

if(NOT GTEST_INC_DIR)
  message(FATAL_ERROR "Couldn't find gtest/gtest.h under folder GTEST_DIR=" ${GTEST_DIR})
endif()

find_path(GTEST_SOURCE_DIR gtest-all.cc
  ${GTEST_DIR}/src
  ${GTEST_DIR}/googletest/src
)
if(NOT GTEST_SOURCE_DIR)
  message(FATAL_ERROR "Couldn't find gtest-all.cc under folder GTEST_DIR=" ${GTEST_DIR})
endif()

set(GTEST_LIB_SOURCES ${GTEST_SOURCE_DIR}/gtest-all.cc)
set(GTEST_MAIN_SOURCES ${GTEST_SOURCE_DIR}/gtest_main.cc)
set(GTEST_INCLUDE_DIRS ${GTEST_INC_DIR}
  ${GTEST_SOURCE_DIR} ${GTEST_SOURCE_DIR}/..)

find_package(Threads REQUIRED)  

add_subdirectory(tests)

