add_library(physics SHARED physics.cc physics.h)

#target_include_directories(${name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

set_property(TARGET physics APPEND PROPERTY
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

