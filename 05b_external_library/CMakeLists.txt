cmake_minimum_required(VERSION 2.8)

set(name hello)

project(${name} C)

add_executable(${name} hello.c)

target_link_libraries(${name} m)
