add_library(mathematics SHARED mathematics.cc mathematics.h)

set_property(TARGET mathematics APPEND PROPERTY
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})


