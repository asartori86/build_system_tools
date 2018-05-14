cmake_minimum_required(VERSION 2.8)

set(name basic)

project(${name} CXX)

add_executable(${name} main.cc
  src/mathematics.cc
  src/physics.cc
  )

include_directories(include)
