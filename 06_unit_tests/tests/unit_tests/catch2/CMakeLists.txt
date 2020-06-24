set(CATCH_DIR "" CACHE PATH "catch2 dir")

find_path(CATCH_INC_DIR "catch2/catch.hpp"
  HINTS
  ${CATCH_DIR}/single_include
  ${CATCH_DIR}/include)

if(NOT CATCH_INC_DIR)
  message(FATAL_ERROR "Couldn't find catch2/catch.hpp under folder CATCH_DIR=" ${CATCH_DIR})
endif()

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INC_DIR})

add_library(catch_main OBJECT catch.cpp)
target_link_libraries(catch_main PUBLIC Catch)
#target_sources(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch.cpp)

# Make test executable

set(_tests_math mathematics_01_catch.cpp)
set(_tests_phys physics_01_catch.cpp)


foreach (_t ${_tests_math})
  add_executable(${_t}_exe ${_t})
  target_link_libraries(${_t}_exe
     mathematics  
   catch_main
    )
  add_test(${_t} ${_t}_exe)
endforeach()

foreach (_t ${_tests_phys})
  add_executable(${_t}_exe ${_t} )
  target_link_libraries(${_t}_exe
     physics
     catch_main
    )
  add_test(${_t} ${_t}_exe)
endforeach()

