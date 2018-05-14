cmake_minimum_required(VERSION 2.8)

set(name shared_libs)

project(${name} CXX)

add_executable(${name} main.cc)

include_directories(include)

add_library(mathematics SHARED src/mathematics.cc)

add_library(physics SHARED src/physics.cc)

target_link_libraries(${name} mathematics  physics)
