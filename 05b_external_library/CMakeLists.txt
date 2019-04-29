cmake_minimum_required(VERSION 2.8)

set(name external_lib)

project(${name} CXX)

add_executable(${name} main.cc)

include_directories(include)

add_definitions("-std=c++11")

add_subdirectory(src)

# it must be in the same file where the executable has been defined
target_link_libraries(${name} mathematics physics)


# FindBoost.cmake is known
find_package(Boost COMPONENTS program_options REQUIRED)
target_link_libraries(${name} boost_program_options)


# find_path(BOOST_INCLUDE_DIR program_options.hpp
#   PATH_SUFFIXES boost
#   /usr/include
#   /usr/local/include
#   /whatever/path/you/should/look
#   )

# find_library(BOOST_LIBRARY
#   NAMES boost_program_options
#   PATHS /usr/lib64 /usr /non/standard/paths
#   )

# target_link_libraries(${name} ${BOOST_LIBRARY})
# target_include_directories(${name} PRIVATE ${BOOST_INCLUDE_DIR})

