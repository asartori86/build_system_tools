cmake_minimum_required(VERSION 2.8)

set(name how_to_test_01)

project(${name} CXX)

add_executable(${name} main.cc)

include_directories(include)

add_definitions("-std=c++11")

add_subdirectory(src)

# it must be in the same file where the executable has been defined
target_link_libraries(${name} mathematics physics)

enable_testing()
add_subdirectory(tests)

