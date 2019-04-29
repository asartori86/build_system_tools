add_library(physics SHARED physics.cc physics.h)

set_property(TARGET physics APPEND PROPERTY
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

