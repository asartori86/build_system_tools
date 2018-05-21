cmake_minimum_required(VERSION 3.9)

set(name customization)

project(${name} CXX)

add_executable(${name} main.cc)

include_directories(include)

###################################################
set(${name}_VERSION_MAJOR 1)
set(${name}_VERSION_MINOR 0)

option(ENABLE_TESTING "Enable testing for this project" OFF)
option(BUILD_PHYSICS "Generate and use physics library" ON)
option(BUILD_MATHEMATICS "Generate and use mathematics library" ON)
#######################################################

add_definitions("-std=c++11")

add_subdirectory(src)

###############################################################
configure_file(
  "${PROJECT_SOURCE_DIR}/include/my_project_config_cmake.h.in"
  "${PROJECT_BINARY_DIR}/my_project_config.h"
  )
include_directories(${PROJECT_BINARY_DIR})
##############################################################


if(BUILD_MATHEMATICS)
  target_link_libraries(${name} mathematics)
endif()


if(BUILD_PHYSICS)
  target_link_libraries(${name} physics)
endif()


if(ENABLE_TESTING)

  enable_testing()

  add_subdirectory(tests)
endif()

message("\n"
        "###\n"
        "#\n"
        "# Library name:\t\t${name}\n"
	"# Library version:\t\t${${name}_VERSION_MAJOR}.${${name}_VERSION_MINOR}\n"
        "#\n"
	"# Build options:\n"
        "#   BUILD_MATHEMATICS:\t\t${BUILD_MATHEMATICS}\n"
        "#   BUILD_PHYSICS:\t\t${BUILD_PHYSICS}\n"
        "#\n"
	"# Project options:\n"
        "#   ENABLE_TESTING:\t\t${ENABLE_TESTING}\n"
        "#\n"
        "###\n"
	)

