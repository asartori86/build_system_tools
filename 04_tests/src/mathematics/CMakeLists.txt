add_library(mathematics SHARED mathematics.cc mathematics.h)

target_include_directories(${name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

