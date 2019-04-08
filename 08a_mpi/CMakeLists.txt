cmake_minimum_required(VERSION 3.1)

set(name hello-mpi)

project(${name} CXX)

add_definitions("-std=c++11")

add_executable(${name} hello.cc)
