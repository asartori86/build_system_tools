cmake_minimum_required(VERSION 3.1)

set(name hello-mpi)

project(${name} CXX)

find_package(MPI)

add_definitions("-std=c++11")

include_directories(${MPI_CXX_INCLUDE_PATH})

add_executable(${name} hello.cc)
target_link_libraries(${name} PRIVATE ${MPI_CXX_LIBRARIES} )
